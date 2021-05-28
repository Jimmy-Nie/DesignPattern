#pragma once

#include <iostream>
#include <string>

/**
 * 虚类：原型模式的接口类
 */
class AbstractPrototype {
public:
    AbstractPrototype() {}
    virtual AbstractPrototype* clone() = 0;
};

class ConcretePrototype : public AbstractPrototype {
public:
    ConcretePrototype() {}

    ConcretePrototype(int num, const std::string& name) {
        this->idNum_ = num;
        this->name_ = name;
        context_ = "Hello, world!";
    }

    void setIdNum(int num) {
        idNum_ = num;
    }

    void setName(const std::string& name) {
        name_ = name;
    }

    void print() {
        std::cout << "The id num: " << idNum_ << std::endl;
        std::cout <<  "The name: " << name_ << std::endl;
        std::cout <<  "The context: " << context_ << std::endl;
    }

    ConcretePrototype* clone() override {
        auto prototype = new ConcretePrototype();
        prototype->setIdNum(1);
        prototype->setName("Jimmy");
        return prototype;
    }

private:
    int idNum_ = 0;
    std::string name_;
    std::string context_;
};