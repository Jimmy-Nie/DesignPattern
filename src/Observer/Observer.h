/**
 * @brief: 观察者模式
 *          应用场景：发布-订阅机制，当一个对象的状态发生改变时，所有依赖于它的对象都要得到通知并自动更新
 * @author: jimmy
 * @date: 2021-06-223
 */

#pragma once

#include <iostream>
#include <string>
#include <utility>
#include <list>
#include <map>

/**
 * @brief: 观察者，当得到通知后，执行自身相应的动作
 */
class Observer {
public:
    virtual void update() = 0;
};

class Student : public Observer {
public:
    Student(std::string  name) : name_(std::move(name)) {}

    void update() override {
        std::cout << name_ << " pretending to learn" << std::endl;
    }

private:
    std::string name_;
};

class Teacher : public Observer {
public:
    Teacher(std::string  name) : name_(std::move(name)) {}

    void update() override {
        std::cout << name_ << " pretending give a lecture" << std::endl;
    }

private:
    std::string name_;
};

/**
 * @brief:  将所有观察者对象的引用保存在list中；
 *          每个主题均可以又多个对象；
 */
class Subject {
public:
    virtual void attach(const std::string& subject, Observer* observer) = 0;
    virtual void detach(const std::string& subject, Observer* observer) = 0;
    virtual void notify(const std::string& subject) = 0;

private:
    std::map<std::string, std::list<Observer*>> sub_obs;
};

class Principal : public Subject {
public:
    Principal(std::string  name) : name_(std::move(name)) {}

    void attach(const std::string& subject, Observer* observer) override {
        std::cout << "Before Add: subject: " << subject << " has element num: " << sub_obs[subject].size() << std::endl;
        sub_obs[subject].push_back(observer);
        std::cout << "After Remove: subject: " << subject << " has element num: " << sub_obs[subject].size() << std::endl;
    }

    void detach(const std::string& subject, Observer* observer) override {
        if(sub_obs.count(subject) == 0) {
            std::cout << "There was no subject: " << subject << std::endl;
        } else {
            std::cout << "Before Remove: subject: " << subject << " has element num: " << sub_obs[subject].size() << std::endl;
            sub_obs[subject].remove(observer);
            std::cout << "After Remove: subject: " << subject << " has element num: " << sub_obs[subject].size() << std::endl;
        }
    }

    void notify(const std::string& subject) override {
        for(auto& ob : sub_obs[subject])
            ob->update();
    }

private:
    std::string name_;
    std::map<std::string, std::list<Observer*>> sub_obs;
};
