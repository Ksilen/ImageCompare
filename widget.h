#ifndef WIDGET_H
#define WIDGET_H
#include "database.h"
#include <QCloseEvent>
#include <QDirIterator>
#include <QFuture>
#include <QImage>
#include <QListWidgetItem>
#include <QMovie>
#include <QStringList>
#include <QTableWidgetItem>
#include <QThread>
#include <QUrl>
#include <QWidget>
#include <QtConcurrent/QtConcurrent>
#include <QtMultimedia/QMediaPlayer>
namespace Ui {
class Widget;
}
class Widget : public QWidget {
    Q_OBJECT
protected:
    void resizeEvent(QResizeEvent* event); //чтобы картинка растягивалась
public:
    explicit Widget(QWidget* parent = 0);
    ~Widget() override;
    void imageCompare();
    void connectDeleteButton();
    void connectDeselect();
    void connectFindButtons();
    void connectFolderButton();
    void connectPresets(); //начальные установки: связи кнопок, начальное их состояние
    void setTitle();
    void setItems();
    void connectRoleForIconAndImage();
    void findImages();
    void addActualFolder();
    void compareImageFromDataBase();
    void createLastTable();
signals:
    void offButtonSignal(); //процесс начался, кнопки спрятались
    void onButtonSignal(); //кнопочки показались
public slots:
    void selectFolderButton();
    void generalSlot(); //Пуск
    void closeEvent(QCloseEvent* event); //событие закрытия
    void offButton();
    void onButton();
    void setIconAndImage(); //отображение иконок и списка картинок
    void deleteSelectedImage();
    void onDeleteAndSelectButtons(); //включить кнопки УДАЛИТЬ и СНЯТЬ ВЫДЕЛЕНИЯ
    void offDeleteAndSelectButtons(); //отключить кнопки УДАЛИТЬ и СНЯТЬ ВЫДЕЛЕНИЯ
    void checkboxTableToList(); //синхронизация checkboxes от table->list
    void checkboxListToTable(); //синхронизация checkboxes2 от list->table
    void imageResize(); //перерисовка tab2 при resize
    void screensaver(); //картинка ожидания
private:
    Ui::Widget* ui;
    DataBase dBase;
    QString searchPath = ""; //путь для поиска
    QString myRootPath = QDir::rootPath();
    QListWidgetItem* iconItems; // Items для иконок
    QTableWidgetItem* imageItems; // Items for tablewidget
    QMovie* screenSaverGif = new QMovie(":/res/milk-mocha.gif"); // gif заставка
    QMediaPlayer* player = new QMediaPlayer();
    QStringList foldersAlreadyExistList; //папки которые уже были, когда вызывается добавить папку для сравнения
    bool firstStart = false; //если 1 запуск, или добавил папку для сравнения
    bool compareFolders = false; // ecли нажато добавить папку, то сравнить: была-ли уже папка добавляема прежде
    bool onScreensaver = false; //вкл gif
};

#endif // WIDGET_H
