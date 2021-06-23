/**
 * @brief: 外观模式
 *          为底层模块/子系统，提供一个统一的一致的高层接口，使得子系统更加容易使用
 *          作用：1. 提供统一接口
 *               2. 减少系统维护的复杂性
 * @author: jimmy
 * @date: 2021-06-23
 */
#pragma once

#include <iostream>
#include <string>

class CentOS {
public:
    void init() {
        std::cout << "CentOS init" << std::endl;
    }

    void displayA() {
        std::cout << "CentOS displayA" << std::endl;
    }
};

class Ubuntu {
public:
    void init() {
        std::cout << "Ubuntu init" << std::endl;
    }

    void displayB() {
        std::cout << "Ubuntu displayA" << std::endl;
    }
};

class RedHat {
public:
    void init() {
        std::cout << "RedHat init" << std::endl;
    }

    void displayC() {
        std::cout << "RedHat displayA" << std::endl;
    }
};

/**
 * @brief: 封装其它的实际的类，不将实际的类暴露给用户
 */
class Linux {
public:
    Linux() {
        centos = new CentOS();
        ubuntu = new Ubuntu();
        redhat = new RedHat();
    }

    void init() {
        centos->init();
        ubuntu->init();
        redhat->init();
    }

    void display() {
        centos->displayA();
        ubuntu->displayB();
        redhat->displayC();
    }

private:
    CentOS* centos = nullptr;
    Ubuntu* ubuntu = nullptr;
    RedHat* redhat = nullptr;
};