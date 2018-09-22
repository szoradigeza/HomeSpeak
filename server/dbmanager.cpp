#include <QtSql/QSqlQuery>
#include <QtCore/QVector>
#include "dbmanager.h"

DBManager::DBManager(const QString &path): dataBaseFilePath(path) {
}

bool DBManager::initDataBase() {
    qSqlDatabase = QSqlDatabase::addDatabase("QSQLITE");
    qSqlDatabase.setDatabaseName(dataBaseFilePath);

    return qSqlDatabase.open();

    /*
    if (!qSqlDatabase.open()) {
        //qDebug() << "Error: no connection with the database";
    } else {
        qDebug() << "Database: connection ok";
    }*/
}

bool DBManager::addUser(const QVector<QString> &data) {

    QSqlQuery qSqlQuery;
    qSqlQuery.prepare("INSERT INTO users id VALUES (:id)");
    qSqlQuery.bindValue(":id", data.at(0));


    return qSqlQuery.exec() && qSqlQuery.next();
}

bool DBManager::checkUser(const QString &id) {
    QSqlQuery qSqlQuery;
    qSqlQuery.prepare("SELECT id FROM users WHERE id = (:id)");
    qSqlQuery.bindValue(":id", id);

    return qSqlQuery.exec() && qSqlQuery.next();
}
