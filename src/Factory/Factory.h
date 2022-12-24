/**
 * @brief: 工厂 模式
 *          定义一个创建对象的接口，由客户端决定到底实例化哪一个类
 * @author: jimmy
 * @date: 2021-06-24
 */

#pragma once
#include <iostream>
#include <string>

/**
 * 抽象产品类
 */
class AbstractProduct {
public:
    virtual void printName() = 0;
    virtual void play() = 0;
};

/**
 * 具体类：basketball
 */
class Basketball : public AbstractProduct {
public:
    Basketball() {
        printName();
        play();
    }

    void printName() override {
        std::cout << "Basketball" << std::endl;
    }

    void play() override {
        std::cout << "Jimmy play Basketball" << std::endl;
    }
};

/**
 * 具体类：Football
 */
class Football : public AbstractProduct {
public:
    Football() {
        printName();
        play();
    }

    void printName() override {
        std::cout << "Football" << std::endl;
    }

    void play() override {
        std::cout << "Jimmy play Football" << std::endl;
    }
};

/**
 * 具体类：Volleyball
 */
class Volleyball : public AbstractProduct {
public:
    Volleyball() {
        printName();
        play();
    }

    void printName() override {
        std::cout << "Volleyball" << std::endl;
    }

    void play() override {
        std::cout << "Jimmy play Volleyball" << std::endl;
    }
};


/**
* 抽象工厂类
*/
class AbstractFactory {
public:
    virtual AbstractProduct* getProduct() = 0;
};

/**
 * 具体类：篮球工厂
 */
class BasketballFactory : public AbstractFactory {
public:
    BasketballFactory() {
        std::cout << "Basketball Factory" << std::endl;
    }

    AbstractProduct* getProduct() override {
       std::cout << "get Basketball" << std::endl;
       return new Basketball();
    }
};

/**
 * 具体类：足球工厂
 */
class FootballFactory : public AbstractFactory {
public:
    FootballFactory() {
        std::cout << "Football Factory" << std::endl;
    }

    AbstractProduct* getProduct() override {
        std::cout << "get Football" << std::endl;
        return new Football();
    }
};

/**
 * 具体类：排球工厂
 */
class VolleyballFactory : public AbstractFactory {
public:
    VolleyballFactory() {
        std::cout << "Volleyball Factory" << std::endl;
    }

    AbstractProduct* getProduct() override {
        std::cout << "get Volleyball" << std::endl;
        return new Volleyball();
    }
};