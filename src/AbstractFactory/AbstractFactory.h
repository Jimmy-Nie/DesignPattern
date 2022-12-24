#pragma once
#include <iostream>

/**
 * 抽象球类
 */
class AbstractBall {
public:
    virtual void play() = 0;
};

/**
 * 具体类：basketball
 */
class Basketball : public AbstractBall {
public:
    Basketball() {
        play();
    }

    void play() override {
        std::cout << "Jimmy play Basketball" << std::endl;
    }
};

/**
 * 具体类：Football
 */
class Football : public AbstractBall {
public:
    Football() {
        play();
    }

    void play() override {
        std::cout << "Jimmy play Football" << std::endl;
    }
};

/**
 * 抽象T桖类
 */
class AbstractShirt {
public:
    virtual void wear() = 0;
};

/**
 * 具体类：BasketballShirt
 */
class BasketballShirt : public AbstractShirt {
public:
    BasketballShirt() {
        wear();
    }

    void wear() override {
        std::cout << "Jimmy wear Basketball shirt" << std::endl;
    }
};

/**
 * 具体类：FootballShirt
 */
class FootballShirt : public AbstractShirt {
public:
    FootballShirt() {
        wear();
    }

    void wear() override {
        std::cout << "Jimmy wear Football Shirt" << std::endl;
    }
};


/**
* 抽象工厂类
*/
class AbstractFactory {
public:
    virtual AbstractBall* getBall() = 0;
    virtual AbstractShirt* getShirt() = 0;
};

/**
 * 具体类：篮球工厂
 */
class BasketballFactory : public AbstractFactory {
public:
    BasketballFactory() {
        std::cout << "Basketball Factory" << std::endl;
    }

    AbstractBall* getBall() override {
        std::cout << "get Basketball" << std::endl;
        return new Basketball();
    }

    AbstractShirt* getShirt() {
        std::cout << "get Basketball shirt" << std::endl;
        return new BasketballShirt();
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

    AbstractBall* getBall() override {
        std::cout << "get Football" << std::endl;
        return new Football();
    }

    AbstractShirt* getShirt() {
        std::cout << "get Football shirt" << std::endl;
        return new FootballShirt();
    }
};