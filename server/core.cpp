#include "core.h"

Core::Core() {
    tcpServer = new TcpServer();
}

Core::~Core() {
    delete tcpServer;
}


