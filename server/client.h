#pragma once

#include <QtCore/QString>
#include <QtNetwork/QHostAddress>

class Client {
public:
    Client(const QHostAddress &ipAddress, const QString &id);
    const QHostAddress &getIpAddress() const;

    const QString &getId() const;

private:
    QHostAddress ipAddress;
    QString id;

};


