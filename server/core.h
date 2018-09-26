#pragma once

#include "tcpserver.h"

class Core {
public:
    Core();
    ~Core();
    TcpServer *tcpServer;
};


