#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setTitle();
    dBase.deleteOldDataBase(); //удалить Бд если программа некорректно завершалась
    connectPresets(); // основные коннекты
}
void Widget::generalSlot()
{
    ui->listOfImages->verticalHeader()->hide(); //очистка списка Картинки от номеров item
    ui->addFolderButton->show(); //показать кнопку "добавить папку для сравнения"
    ui->findButton->setText("Найти в новой папке");
    ui->tabWidget->setCurrentIndex(2);
    player->setMedia(QUrl("qrc:/res/zzzv.mp3"));
    if (firstStart == false) { //если первый запуск или нажата кнопка "добавить папку"
        if (foldersAlreadyExistList.isEmpty()) {
            foldersAlreadyExistList.append(searchPath);
        }
        screensaver(); //запустить gif-ку
        imageCompare(); //запустить сравнение
    } else { //ИСКАТЬ ЗАНОВО
        dBase.deleteOldDataBase();
        compareFolders = false;
        foldersAlreadyExistList.clear();
        foldersAlreadyExistList.append(searchPath);
        screensaver();
        imageCompare();
    }
}
void Widget::connectPresets()
{
    ui->addFolderButton->hide();
    connect(ui->horizontalSlider, SIGNAL(sliderMoved(int)), ui->labelForSlider, SLOT(setNum(int)));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
        ui->addFolderButton, //отключить кнопку "добавить папку для сравнения" если
        SLOT(hide())); //сдвинут слайдер точности
    connect(this, SIGNAL(offButtonSignal()), SLOT(offButton()));
    connect(this, SIGNAL(onButtonSignal()), SLOT(onButton()));
    connect(this, SIGNAL(offButtonSignal()), SLOT(offDeleteAndSelectButtons()));
    connect(this, SIGNAL(onButtonSignal()), SLOT(setIconAndImage())); //процесс сравнения остановись, иконки покажись

    connectFolderButton(); //кнопка выбора папки для поиска
    connectFindButtons(); //кнопки "начать поиск" и "добавить для поиска"
    offDeleteAndSelectButtons(); //сделать кнопки "удалить" и "снять выделенное"не активными
    connectDeleteButton(); //кнопочка "удалить выделенные"
    connectDeselect(); //"снять выделения"
}
void Widget::imageCompare()
{
    QtConcurrent::run([=]() {
        onScreensaver = true; //чтоб ресайзилось gif ожидания
        ui->widgetForIcons->clear(); //очистить widget иконки
        ui->listOfImages->clear(); //очистить список картинки
        ui->imagePropertiesLabel->clear(); //очистить свойства картинки
        emit(offButtonSignal()); //сигнал о запуске процесса -> кнопки спрятались,чтоб не нажать еще раз
        findImages();
        if (dBase.quitFlow) //из потока выход, если программу закрыли
            return;
        addActualFolder();
        int proc = ui->horizontalSlider->value(); // значение из слайдера для сравнения
        dBase.compareImageFromDataBase(proc);
        dBase.createLastTable();
        dBase.setIconInDataBase();
        dBase.setCheckOnCopy();
        firstStart = true; //первый запуск состоялся
        dBase.closeDataBase();
        emit(onButtonSignal());
    });
}
void Widget::setIconAndImage() //установить иконки и список картинок
{ // blockSignals,а то крах, т.к.connect checkboxes иконок и картинок
    ui->widgetForIcons->blockSignals(true);
    ui->listOfImages->blockSignals(true);
    ui->listOfImages->setRowCount(0);
    ui->listOfImages->horizontalHeader()->hide();
    ui->listOfImages->setColumnCount(1); // Указываем число колонок
    ui->listOfImages->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->listOfImages->horizontalHeader()->stretchLastSection();
    setItems();
    ui->listOfImages->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->widgetForIcons->blockSignals(false);
    ui->listOfImages->blockSignals(false);
    connectRoleForIconAndImage();
    //установить картинки
    ui->listOfImages->verticalHeader()->show();
    ui->listOfImages->selectRow(0);
    screenSaverGif->stop();
    onScreensaver = false; //чтоб НЕ ресайзилось gif ожидания
    imageResize();
    onDeleteAndSelectButtons();
    player->setVolume(50);
    player->play();
}
void Widget::setItems() //установка Items иконок и картинок
{
    for (int i = 0; i < dBase.mainTableSize; ++i) {
        //установить Иконки
        QPixmap outPixmap;
        outPixmap.loadFromData(dBase.modelForDataBase->data(dBase.modelForDataBase->index(i, 1)).toByteArray());
        iconItems = new QListWidgetItem("", ui->widgetForIcons);
        iconItems->setIcon(outPixmap);
        iconItems->setToolTip(
            dBase.modelForDataBase->data(dBase.modelForDataBase->index(i, 0)).toString()); //адрес картинки при наведении
        iconItems->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEditable | Qt::ItemIsEnabled); // разрешаем редактировать
        if (dBase.modelForDataBase->data(dBase.modelForDataBase->index(i, 3)).toInt() > 0) {
            iconItems->setCheckState(
                Qt::Checked); //устанавливаем флажки в состояние (выбрано)
        } else {
            iconItems->setCheckState(Qt::Unchecked);
        }
        //установить List Картинок
        ui->listOfImages->insertRow(i);
        imageItems = new QTableWidgetItem();
        imageItems->setText(dBase.modelForDataBase->data(dBase.modelForDataBase->index(i, 5)).toString());
        imageItems->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEditable | Qt::ItemIsEnabled);
        if (dBase.modelForDataBase->data(dBase.modelForDataBase->index(i, 3)).toInt() > 0) {
            imageItems->setCheckState(
                Qt::Checked); //устанавливаем флажки в состояние (выбрано)
        } else {
            imageItems->setCheckState(Qt::Unchecked);
        }
        ui->listOfImages->setItem(i, 0, imageItems);
    }
}
void Widget::connectRoleForIconAndImage()
{
    connect(ui->listOfImages, SIGNAL(cellChanged(int, int)), SLOT(checkboxTableToList()));
    connect(ui->widgetForIcons, SIGNAL(itemChanged(QListWidgetItem*)), SLOT(checkboxListToTable()));
    connect(ui->tabWidget, SIGNAL(currentChanged(int)), SLOT(imageResize()));
    connect(ui->listOfImages, SIGNAL(itemSelectionChanged()), SIGNAL(cellPressed(int, int)));
    connect(ui->listOfImages, SIGNAL(cellPressed(int, int)),
        SLOT(imageResize())); //если кликнуто мышкой,то перерисовать картинку
    connect(ui->listOfImages, SIGNAL(itemSelectionChanged()),
        SLOT(imageResize())); //если нажаты стрелочки,то перерисовать картинку
}
void Widget::checkboxTableToList()
{
    for (int i = 0; i < dBase.mainTableSize; ++i) {
        if (ui->listOfImages->item(i, 0)->checkState()) {
            ui->widgetForIcons->item(i)->setCheckState(Qt::Checked);
        } else {
            ui->widgetForIcons->item(i)->setCheckState(Qt::Unchecked);
        }
    }
}
void Widget::checkboxListToTable()
{
    for (int i = 0; i < dBase.mainTableSize; ++i) {
        if (ui->widgetForIcons->item(i)->checkState()) {
            ui->listOfImages->item(i, 0)->setCheckState(Qt::Checked);
        } else {
            ui->listOfImages->item(i, 0)->setCheckState(Qt::Unchecked);
        }
    }
}
void Widget::deleteSelectedImage()
{
    offDeleteAndSelectButtons(); //чтоб 2 раза не нажать удалить
    for (int i = 0; i < dBase.mainTableSize; ++i) {
        if (ui->widgetForIcons->item(i)->checkState()) { //если чекнут, то удалить
            QString fileDeletePath = dBase.modelForDataBase->data(dBase.modelForDataBase->index(i, 0)).toString();
            QFile::setPermissions(fileDeletePath,
                QFile::ReadOwner | QFile::WriteOwner);
            QFile::remove(fileDeletePath);
        }
    }
    ui->listOfImages->clear();
    ui->listOfImages->verticalHeader()->hide();
    ui->widgetForIcons->clear();
    ui->tabWidget->setCurrentIndex(0);
    firstStart = true; //к начальным настройкам
    ui->addFolderButton->hide();
}
void Widget::onDeleteAndSelectButtons()
{
    ui->deleteSelectedButton->setEnabled(true);
    ui->deleteSelectedButton2->setEnabled(true);
    ui->notSelectButton->setEnabled(true);
    ui->notSelectButton2->setEnabled(true);
}
void Widget::offDeleteAndSelectButtons()
{
    ui->deleteSelectedButton->setEnabled(false);
    ui->deleteSelectedButton2->setEnabled(false);
    ui->notSelectButton->setEnabled(false);
    ui->notSelectButton2->setEnabled(false);
}
void Widget::offButton() //спрятать кнопки на время вычислений
{
    ui->findButton->setVisible(false);
    ui->addFolderButton->setVisible(false);
    ui->horizontalSlider->setVisible(false);
    ui->folderButton->setEnabled(false);
}
void Widget::onButton()
{
    ui->findButton->setVisible(true);
    ui->addFolderButton->setVisible(true);
    ui->horizontalSlider->setVisible(true);
    ui->folderButton->setEnabled(true);
}
void Widget::resizeEvent(QResizeEvent* event) //изображение в окошке "картинка"
{
    if (!onScreensaver) {
        imageResize();
    } else {
        screensaver();
    }
    QWidget::resizeEvent(event);
}
void Widget::imageResize()
{
    int i = ui->listOfImages->currentRow(); //выделенная строка
    QPixmap pixm;
    pixm.loadFromData(dBase.modelForDataBase->data(dBase.modelForDataBase->index(i, 8)).toByteArray());
    ui->screenImage->setPixmap(pixm.scaled(ui->screenImage->size(), Qt::KeepAspectRatio));
    //отображение параметров картинки
    ui->imagePropertiesLabel->setText(dBase.modelForDataBase->data(dBase.modelForDataBase->index(i, 0)).toString() + "\n"
        + dBase.modelForDataBase->data(dBase.modelForDataBase->index(i, 6)).toString() + " " + dBase.modelForDataBase->data(dBase.modelForDataBase->index(i, 7)).toString());
}
void Widget::screensaver()
{
    QSize movieSize = ui->screenImage->size();
    screenSaverGif->setScaledSize(movieSize);
    ui->screenImage->setMovie(screenSaverGif);
    screenSaverGif->start();
}
void Widget::connectFolderButton() //кнопка выбора папки
{
    ui->folderButton->setIcon(QIcon(":/res/icon.png"));
    ui->folderButton->setIconSize(ui->folderButton->size());
    connect(ui->folderButton, SIGNAL(clicked(bool)), SLOT(selectFolderButton()));
    ui->lineEdit->setText(myRootPath);
}
void Widget::selectFolderButton()
{
    searchPath = QFileDialog::getExistingDirectory(0, "Выбор папки", myRootPath);
    if (searchPath == "") {
        searchPath = ui->lineEdit->text();
    }
    ui->lineEdit->setText(searchPath);
}
void Widget::connectFindButtons()
{
    connect(ui->findButton, SIGNAL(clicked(bool)), SLOT(generalSlot())); //"сравнить"
    connect(ui->addFolderButton, &QPushButton::clicked, //"добавить для сравнения"
        [=]() {
            firstStart = false;
            compareFolders = true; //проверка на то - была папка али нет
            generalSlot();
        });
}
void Widget::connectDeleteButton()
{
    connect(ui->deleteSelectedButton, SIGNAL(clicked(bool)), SLOT(deleteSelectedImage()));
    connect(ui->deleteSelectedButton2, SIGNAL(clicked(bool)), SLOT(deleteSelectedImage()));
}
void Widget::connectDeselect()
{
    connect(ui->notSelectButton, &QPushButton::clicked, [=]() {
        for (int i = 0; i < dBase.mainTableSize; ++i) {
            ui->widgetForIcons->item(i)->setCheckState(Qt::Unchecked);
        }
    });
    connect(ui->notSelectButton2, &QPushButton::clicked, [=]() {
        for (int i = 0; i < dBase.mainTableSize; ++i) {
            ui->widgetForIcons->item(i)->setCheckState(Qt::Unchecked);
            ui->listOfImages->item(i, 0)->setCheckState(Qt::Unchecked);
        }
    });
}
void Widget::setTitle()
{
    this->setWindowTitle("Сравнить Картинки");
    QIcon ic(":/res/iccoon.png");
    this->setWindowIcon(ic);
    ui->tabWidget->setCurrentIndex(0);
}
void Widget::closeEvent(QCloseEvent* event) //закрытие приложения
{
    event->ignore();
    dBase.quitFlow = true; //условие остановки QConcurrent
    QThreadPool::globalInstance()->waitForDone(); //подождать завершения остановки
                                                  //потока,иначе БД не удаляется
    dBase.deleteOldDataBase(); //удалить БД
    event->accept();
}
Widget::~Widget()
{
    delete ui;
}
void Widget::findImages()
{
    dBase.createDataBase();
    dBase.createFirstTable();
    dBase.findImage(searchPath, foldersAlreadyExistList, compareFolders);
}
void Widget::addActualFolder() //добавить в foldersAlreadyExistList,путь папки, которая сейчас проверялась
{
    bool xx = true;
    foreach (QString ddir, foldersAlreadyExistList) {
        if (ddir != searchPath) {
            xx = true;
        } else {
            xx = false;
            break;
        }
    }
    if (xx) {
        foldersAlreadyExistList.append(searchPath);
    }
}
