//
// Created by Administrator on 2021/6/24.
//

//ClassFactory.h

#pragma once

#include <string>
#include <map>
typedef void* (*PTRCreateObject)(void);

//工厂类的定义
class ClassFactory {
private:
    std::map<std::string, PTRCreateObject> m_classMap;
    ClassFactory() {}; //构造函数私有化

public:
    void* getClassByName(std::string className);
    void registClass(std::string name, PTRCreateObject method);
    static ClassFactory& getInstance();
};

//工厂类的实现

//@brief:获取工厂类的单个实例对象
ClassFactory& ClassFactory::getInstance() {
    static ClassFactory sLo_factory;
    return sLo_factory;
}

//@brief:通过类名称字符串获取类的实例
void* ClassFactory::getClassByName(std::string className) {
    auto iter = m_classMap.find(className);
    if (iter == m_classMap.end())
        return NULL;
    else
        return iter->second();
}

//@brief:将给定的类名称字符串和对应的创建类对象的函数保存到map中
void ClassFactory::registClass(std::string name, PTRCreateObject method) {
    m_classMap.insert(make_pair(name, method));
    std::cout<<"The map size:"<<m_classMap.size()<<std::endl;
}



//注册动作类
class RegisterAction{
public:
    RegisterAction(std::string className,PTRCreateObject ptrCreateFn){
        ClassFactory::getInstance().registClass(className,ptrCreateFn);
    }
};

#define REGISTER(className)                                             \
    className* objectCreator##className(){                              \
        return new className;                                           \
    }                                                                   \
    RegisterAction g_creatorRegister##className(                        \
        #className,(PTRCreateObject)objectCreator##className)