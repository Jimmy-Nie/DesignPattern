/**************************************************
 * 单例模式应考虑到线程安全等
 * 本单例，简单易行，且线程安全
 *************************************************/
#pragma once
#include <iostream>

class Singleton {
public:
    static Singleton* getInstance() {
        static Singleton instance;
        return &instance;
    }

    void setNum(int num) {
        number_ = num;
    }

    int getNum() {
        std::cout << "number=" << number_ << std::endl;
        return number_;
    }

private:
    int number_ = -1;
};

