#include "database.h"

void DataBase::deleteOldDataBase()
{
    QSqlDatabase db1 = QSqlDatabase::addDatabase("QSQLITE");
    db1.setDatabaseName("example");
    db1.open();
    db1.close();
    QFile ddb("example"); //Удаление БД
    ddb.remove();
}
void DataBase::createDataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example"); //БД
    db.open();
}
void DataBase::createFirstTable()
{
    QSqlQuery q1(db);
    q1.exec("create table mytable(" //ТАБЛИЦА ДЛЯ ВСЕХ КАРТИНОК И СУММЫ ЦВЕТА
            "img varchar(255),"
            "pix integer);");
}
void DataBase::findImage(QString searchPath, QStringList foldersAlreadyExistList, bool compareFolders)
{
    QSqlQuery q1(db);
    q1.prepare("insert into mytable(img,pix) "
               "values(:path,:pix);");
    long long allColor = 0; //переменная для общего цвета
    int r = 0;
    int g = 0;
    int b = 0;
    QDirIterator iter(searchPath, QDir::NoFilter, QDirIterator::Subdirectories);

    while (iter.hasNext()) {
        if (quitFlow) { //Если из программы вышли,из цикла тоже надо
            break;
        }
        bool cont = false;
        if (compareFolders) { //Если "добавить папку",а вдруг она уже была...все в foldersAlreadyExistList
            foreach (QString ddir, foldersAlreadyExistList) {
                if (searchPath == ddir) {
                    cont = true;
                }
            }
        }
        if (cont) {
            cont = false;
            break;
        } //если папка была,(внутри другой например) то зачем пересчитывать её? break
        QFile fileWithImage(iter.next());
        QFileInfo inf(fileWithImage);
        QString infSuf = inf.suffix();
        if (infSuf == "jpg" || infSuf == "jpeg" || infSuf == "bmp" || infSuf == "png") {
            QImage changedImage(inf.absoluteFilePath());
            if (changedImage.width() < campareImageSize || changedImage.height() < campareImageSize) { //чтоб не было out of range
                QImage withoutOut(campareImageSize, campareImageSize, QImage::Format_RGB32);
                QPoint destPos = QPoint(0, 0);
                QPainter painter(&withoutOut);
                QPixmap pixmap(campareImageSize, campareImageSize);
                pixmap.fill(Qt::transparent);
                QRect r = pixmap.rect();
                painter.setBrush(QBrush(Qt::yellow));
                painter.fillRect(r, painter.brush());
                painter.drawImage(destPos, changedImage);
                painter.end();
                changedImage = withoutOut;
            }
            changedImage.scaled(campareImageSize, campareImageSize, Qt::KeepAspectRatio, Qt::FastTransformation);
            allColor = 0; //переменная для общего цвета
            for (int i = 0; i < campareImageSize; ++i) {
                for (int j = 0; j < campareImageSize; ++j) {
                    r = qRed(changedImage.pixel(i, j));
                    g = qGreen(changedImage.pixel(i, j));
                    b = qBlue(changedImage.pixel(i, j));
                    allColor = allColor + (r + g + b);
                }
            }
            q1.bindValue(":path", inf.filePath());
            q1.bindValue(":pix", allColor);
            q1.exec();
        }
    }
}
void DataBase::compareImageFromDataBase(int proc)
{
    QSqlQuery q1(db);
    q1.exec("delete from mainTable;"); //если нажато ДОБАВИТЬ ПАПКУ, то нужен пересчет mainTable
    q1.exec("delete from mytable4;");
    q1.exec("create table mainTable("
            "img0 varchar(255),"
            "pixx integer);");
    q1.exec("update sqlite_sequence set seq=0  WHERE Name='mainTable';");
    q1.exec("update sqlite_sequence set seq=0  WHERE Name='mytable4';");
    q1.prepare("insert into mainTable(img0,pixx) "
               "select img,pix from mytable t1 "
               "where exists (select 1 from mytable t2 "
               "where ((t1.pix-t2.pix)=0 or ((t1.pix*100/t2.pix)>:proc "
               "and (t1.pix*100/t2.pix)<101)) "
               "and t1.img<>t2.img);");
    q1.bindValue(":proc", proc);
    q1.exec();
}
void DataBase::createLastTable()
{
    QSqlQuery q1(db);
    q1.exec("create table mytable4("
            "img0 varchar(255),"
            "img_min BLOB,"
            "id integer PRIMARY KEY AUTOINCREMENT,"
            "chek integer,"
            "pixx integer,"
            "name varchar(255),"
            "resolution varchar(255),"
            "size varchar(255),"
            "img_max BLOB);");
    q1.exec("insert into mytable4(img0,pixx) " //добавить отсортированные по Id, иначе галочки не ставятся
            "select img0,pixx from mainTable order by pixx;");
}
void DataBase::setIconInDataBase()
{
    QSqlQuery q1(db);
    q1.exec("SELECT COUNT(*) FROM mytable4;"); //сколько строк получилось
    if (q1.next()) {
        mainTableSize = q1.value(0).toInt();
    }
    q1.exec("SELECT img0 FROM mytable4;"); // адреса однаковых картинок
    QString str1;
    pathFromMainTable.clear();
    while (q1.next()) {
        str1 = q1.value(0).toString();
        pathFromMainTable.append(str1);
    }
    for (int i = 0; i < mainTableSize; ++i) { //добавить иконки в БД
        QString piiix = pathFromMainTable.at(i);
        QImage imgTemp(piiix);
        QByteArray byteMax;
        QBuffer bufMax(&byteMax);
        bufMax.open(QIODevice::WriteOnly);
        imgTemp.scaled(bigImageScaleSize, bigImageScaleSize, Qt::KeepAspectRatio).save(&bufMax, "PNG"); //размер Thumnails
        bufMax.close();
        QByteArray byte;
        QBuffer buf(&byte);
        buf.open(QIODevice::WriteOnly);
        imgTemp.scaled(100, 100, Qt::KeepAspectRatio).save(&buf, "PNG"); //размер Thumnails
        buf.close();
        q1.prepare("UPDATE mytable4 SET img_min = :icon, img_max = :iconMax WHERE id=:ii;");
        q1.bindValue(":ii", i + 1);
        q1.bindValue(":iconMax", byteMax);
        q1.bindValue(":icon", byte);
        q1.exec();
        QPixmap kk;
        kk.loadFromData(byte);
        //имя, размер и разрешение
        QFile file1(piiix);
        QFileInfo inf1(file1);
        QString infName = inf1.fileName();
        int infSize1 = inf1.size() / 1024;
        QString infSize;
        infSize.setNum(infSize1);
        infSize.append(" KB");
        int width = QPixmap(piiix).width();
        int height = QPixmap(piiix).height();
        QString widthss;
        QString heights;
        widthss.setNum(width);
        heights.setNum(height);
        QString resolution = widthss + "x" + heights;
        q1.prepare("UPDATE mytable4 SET name = :n,resolution = :r,size = :s "
                   "WHERE id=:ii;");
        q1.bindValue(":n", infName);
        q1.bindValue(":r", resolution);
        q1.bindValue(":s", infSize);
        q1.bindValue(":ii", i + 1);
        q1.exec();
    }
}
void DataBase::setCheckOnCopy()
{
    QSqlQuery q1(db);
    q1.exec("UPDATE mytable4 set chek = 1 where(" //для галочек на дубликаты 100%
            "id in (SELECT id FROM mytable4 t1 "
            "WHERE EXISTS(SELECT pixx,id FROM mytable4 t2 "
            "WHERE((t1.pixx = t2.pixx) and (t1.size=t2.size) "
            "and t2.id=t1.id-1))));");
}
void DataBase::closeDataBase()
{
    modelForDataBase->setQuery("select * from mytable4 order by id;"); //ИТОГ ВСЕХ МАНИПУЛЯЦИЙ
    db.close(); //закрыть БД
}
