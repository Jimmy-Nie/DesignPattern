#pragma once

#include <string>
#include <iostream>

class Person {
public:
    Person() {}
    Person(const std::string& name) : name_(name) {}
    virtual void show() {
        std::cout << "Person name: " << name_ << std::endl;
    }

private:
    std::string name_;
};

/**
 * 装饰器：服饰类
 */
class Finery : public Person {
public:
    void decorate(Person* person) {
        this->person_ = person;
    }

    void show() override {
        if(person_) {
            person_->show();
        } else {
            std::cout<< "Error: no person ..." << std::endl;
        }
    }

private:
    Person* person_;
};

/**
 * 具体服饰类
 */
class Tshirt : public Finery {
public:
    void show() override {
        std::cout << "Tshirt ..." << std::endl;
        Finery::show();
    }
};

class Trouser : public Finery {
public:
    void show() override {
        std::cout << "Trouser ..." << std::endl;
        Finery::show();
    }
};

class Suit : public Finery {
public:
    void show() override {
        std::cout << "Suit ..." << std::endl;
        Finery::show();
    }
};

class LeatherShoes : public Finery {
public:
    void show() override {
        std::cout << "LeatherShoes ..." << std::endl;
        Finery::show();
    }
};