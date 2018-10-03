#pragma once

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

class TcpServer : public QObject {
    Q_OBJECT

public:
    explicit TcpServer(QObject * parent = nullptr);
    ~TcpServer();

signals:

public slots:
    void newConnection_slot();

private:
    QTcpServer *server = nullptr;
};
