#pragma once

#include <QtSql>
#include <QtCore/QString>
#include <QtSql/QSqlDatabase>

class DBManager {
public:
    DBManager(const QString &path);
    bool initDataBase();
    bool addUser(const QVector<QString> &data);
    bool checkUser(const QString &id);

private:
    QString dataBaseFilePath;
    QSqlDatabase qSqlDatabase;
};


