#ifndef DATABASE_H
#define DATABASE_H
#include <QBuffer>
#include <QDirIterator>
#include <QFileDialog>
#include <QPainter>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlRecord>
class DataBase {
public:
    void deleteOldDataBase();
    void createDataBase();
    void createFirstTable();
    void findImage(QString searchPath, QStringList foldersAlreadyExistList, bool compareFolders);
    void compareImageFromDataBase(int proc);
    void createLastTable();
    void setIconInDataBase();
    void setCheckOnCopy();
    void closeDataBase();
    QSqlQueryModel* modelForDataBase = new QSqlQueryModel; //запросы из БД
    int mainTableSize = 0;
    bool quitFlow = false; //чтоб завершить поток при выходе из программы
private:
    QSqlDatabase db;
    QStringList pathFromMainTable;
    int campareImageSize = 500; //размер сравниваемых уменьшенных картинок
    int bigImageScaleSize = 1000; //размер (и качество) большой картинки
};

#endif // DATABASE_H
