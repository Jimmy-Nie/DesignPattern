/**
 * @brief: 反射机制
 *          指程序在运行时，访问、检测和修改它本身状态或行为的一种能力
 *          根据类名称（string），获取类和类中的方法/属性等
 * @author: jimmy
 * @date: 2021-06-223
 */

#pragma once

#include <iostream>
#include <string>
#include <map>
#include <functional>


//std::function<void* (void)> ptrCreateFactory;
typedef void* (*ptrCreateFactory)(void);

class Factory {
public:
    static Factory& getInstance() {
        static Factory instance;
        return instance;
    }

    void* getClassByName(const std::string& name) {
        //if(class_map_.count(name) == 0) {
        auto it = class_map_.find(name);
        if(it == class_map_.end()) {
            std::cout << "No class named: " << name << std::endl;
            return nullptr;
        }
        return it->second();
        //return reinterpret_cast<void*>(class_map_[name]);
    }

    void registerClass(const std::string& name, ptrCreateFactory method) {
        class_map_.insert(make_pair(name, method));
    }

    int getMapSize() {return class_map_.size();}
private:
    Factory() {}
    std::map<std::string, ptrCreateFactory> class_map_;
};


class RegisterAction {
public:
    RegisterAction(const std::string& name, ptrCreateFactory method) {
        Factory::getInstance().registerClass(name, method);
    }
};


#define REGISTER(className) \
    className* creat##className() { return new className; } \
    RegisterAction g_register##className(#className, (ptrCreateFactory)creat##className)
