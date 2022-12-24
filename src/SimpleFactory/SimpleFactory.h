/**
 * @brief: 简单工厂 模式
 *          将需要实例化的类都放到工厂类中去实现，减少耦合
 * @author: jimmy
 * @date: 2021-06-23
 */

#pragma once
#include <iostream>

/**
 * 创建sport的抽象类（接口）
 * */
class AbstractSportProduct {
public:
    AbstractSportProduct() {}

    void printName();
    void play();
};

/**
* 创建具体类：Basketball
*/
class Basketball : public AbstractSportProduct {
public:
    Basketball() {
        printName();
        play();
    }

    ///具体方法
    void printName() {
        std::cout << "Jimmy get the Basketball" << std::endl;
    }
    void play() {
        std::cout << "Jimmy play the Basketball" << std::endl;
    }
};

/**
* 创建具体类：Football
*/
class Football : public AbstractSportProduct {
public:
    Football() {
        printName();
        play();
    }

    ///具体方法
    void printName() {
        std::cout << "Jimmy get the Football" << std::endl;
    }
    void play() {
        std::cout << "Jimmy play the Football" << std::endl;
    }
};

/**
* 创建具体类：Volleyball
*/
class Volleyball : public AbstractSportProduct {
public:
    Volleyball() {
        printName();
        play();
    }

    ///具体方法
    void printName() {
        std::cout << "Jimmy get the Volleyball" << std::endl;
    }
    void play() {
        std::cout << "Jimmy play the Volleyball" << std::endl;
    }
};

/**
* 创建工厂类：
*/
class Factory {
public:
    AbstractSportProduct* getSportProduct(const std::string& productName) {
        AbstractSportProduct* product = nullptr;

        if(productName == "Basketball") {
            product = new Basketball();
        } else if(productName == "Football") {
            product = new Football();
        } else if(productName == "Volleyball") {
            product = new Volleyball();
        } else {
            std::cout << "The product name: " << productName << " was not found!!" << std::endl;
        }

        return product;
    }
};