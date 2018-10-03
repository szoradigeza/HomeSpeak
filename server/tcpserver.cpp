#include <QtNetwork>
#include <QtCore>
#include <QDebug>
#include "tcpserver.h"

TcpServer::TcpServer(QObject *parent) :
    QObject(parent) {
    server = new QTcpServer(this);

    connect(server, &QTcpServer::newConnection, this, &TcpServer::newConnection_slot);

    if (!server->listen(QHostAddress::AnyIPv4, 8085)) {
        qDebug() << "Server could not start!";
    } else {
        qDebug() << "Server started successfully!";
    }
}

void TcpServer::newConnection_slot() {
    QTcpSocket *socket = server->nextPendingConnection();

    QByteArray data = socket->readAll();

    socket->write("Hello client, this is my respone:" + data + "\r\n");
    socket->flush();

    socket->waitForBytesWritten(3000);

    socket->close();
}

TcpServer::~TcpServer() {
    delete server;
}
