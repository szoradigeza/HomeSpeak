#pragma once

#include <QtWidgets/QDialog>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>

class QLabel;
class QTcpServer;
class QNetworkSession;

class TcpServer : public QDialog {
    Q_OBJECT

public:
    TcpServer(QWidget * parent = nullptr);

public slots:
    void sessionOpened();
    void sendFortune();

private:
    QLabel *statusLabel = nullptr;
    QTcpServer *tcpServer = nullptr;
    QVector<QString> fortunes;
    QNetworkSession *networkSession = nullptr;
};
