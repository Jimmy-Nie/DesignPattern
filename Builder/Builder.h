#pragma once

#include <iostream>
#include <string>

/**
 * 具体类：建造的产品
 */
class House {
public:
    void setFloor(const std::string& floor) {
        this->floor_ = floor;
    }

    void setWall(const std::string& wall) {
        this->wall_ = wall;
    }

    void setRoof(const std::string& roof) {
        this->roof_ = roof;
    }

    void printHouse() {
        std::cout << "Floor: " << floor_ << std::endl;
        std::cout << "Wall: " << wall_ << std::endl;
        std::cout << "Roof: " << roof_ << std::endl;
    }

private:
    std::string floor_;
    std::string wall_;
    std::string roof_;
};


/**
 * 纯虚类：接口类，建造产品
 */
class AbstractBuilder {
public:
    AbstractBuilder() {
        house = new House();
    }

    virtual void buildFloor() = 0;
    virtual void buildWall() = 0;
    virtual void buildRoof() = 0;
    virtual House* getHouse() = 0;

    House* house;
};

class concreteBuilderA : public AbstractBuilder {
public:
    void buildFloor() override {
        house->setFloor(builder);
    }

    void buildWall() override {
        house->setWall(builder);
    }

    void buildRoof() override {
        house->setRoof(builder);
    }

    House* getHouse() override {
        return this->house;
    }

private:
    const std::string builder = "Builder_A";
};

class concreteBuilderB : public AbstractBuilder {
public:
    void buildFloor() override {
        house->setFloor(builder);
    }

    void buildWall() override {
        house->setWall(builder);
    }

    void buildRoof() override {
        house->setRoof(builder);
    }

    House* getHouse() override {
        return this->house;
    }

private:
    const std::string builder = "Builder_B";
};

/**
 * 指导者：可以不要
 */
class Director {
public:
    Director() {}

    void setBuilder(AbstractBuilder* builder) {
        builder_ = builder;
    }

    House* buildHouse() {
        builder_->buildFloor();
        builder_->buildRoof();
        builder_->buildWall();

        return builder_->getHouse();
    }

private:
    AbstractBuilder* builder_;
};