#include "client.h"


Client::Client(const QHostAddress &ipAddress, const QString &id) :
    ipAddress(ipAddress),
    id(id)  {

}

const QHostAddress &Client::getIpAddress() const {
    return ipAddress;
}

const QString &Client::getId() const {
    return id;
}
