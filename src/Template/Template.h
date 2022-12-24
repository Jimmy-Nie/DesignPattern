/**
 * @brief: 模板方法模式
 *          将不变的行为（共用的部分）移到父类中实现，特殊实现在子类中完成
 *          优点：防止每个类中都有重复的代码；便面当改动某一个功能，每个类都需要改动的问题
 * @author: jimmy
 * @date: 2021-06-223
 */

#include <iostream>
#include <string>

class Wifi {
public:
    void restartWifi() {
        stopWifi();
        startWifi();
    }

    virtual void startWifi() = 0;
    virtual void stopWifi() = 0;
    virtual void setSsidPsk(const std::string& ssid, const std::string& psk) = 0;
};

class Ubuntu : public Wifi{
    void startWifi() override {
        std::cout << "Ubuntu startWifi" << std::endl;
    }

    void stopWifi() override {
        std::cout << "Ubuntu stopWifi" << std::endl;
    }

    void setSsidPsk(const std::string& ssid, const std::string& psk) override {
        std::cout << "Ubuntu SSID: " << ssid << ", PSK: " << psk << std::endl;
    }
};

class CentOS : public Wifi {
    void startWifi() override {
        std::cout << "CentOS startWifi" << std::endl;
    }

    void stopWifi() override {
        std::cout << "CentOS stopWifi" << std::endl;
    }

    void setSsidPsk(const std::string& ssid, const std::string& psk) override {
        std::cout << "CentOS SSID: " << ssid << ", PSK: " << psk << std::endl;
    }
};