#pragma once

#include <iostream>
#include <string>

/**
 * 纯虚类：通信接口
 */
class Communication {
public:
    virtual void sendMsg() = 0;
    virtual void recvMsg() = 0;
};

/**
 * 定义具体类：TCP & UDP
 */
class TCP {
public:
    void sendTcpMsg() {
        std::cout << "Send TCP message!" << std::endl;
    }

    void recvTcpMsg() {
        std::cout << "Receive TCP message!" << std::endl;
    }
};

class UDP {
public:
    void sendUdpMsg() {
        std::cout << "Send UDP message!" << std::endl;
    }

    void recvUdpMsg() {
        std::cout << "Receive UDP message!" << std::endl;
    }
};

class NetworkAdapter : public Communication {
public:
    NetworkAdapter() {
        udp = new UDP();
        tcp = new TCP();
    }

    ~NetworkAdapter() {
        delete udp;
        delete tcp;
        udp = nullptr;
        tcp = nullptr;
    }

    void sendMsg() override {
        udp->sendUdpMsg();
        tcp->sendTcpMsg();
    }

    void recvMsg() override {
        udp->recvUdpMsg();
        tcp->recvTcpMsg();
    }

private:
    UDP* udp = nullptr;
    TCP* tcp = nullptr;
};