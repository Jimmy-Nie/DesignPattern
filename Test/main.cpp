#include <iostream>

#include "ClassFactory.h"
//#include "register.h"

//test class
class TestClass {
public:
    void m_print() {
        std::cout << "hello TestClass" << std::endl;
    };

    int i = 100;
};

class TestClassA {
public:
    void m_print() {
        std::cout << "hello TestClassA" << std::endl;
    };

    int i = 10;
};

REGISTER(TestClass);
REGISTER(TestClassA);

int main(int argc, char* argv[]) {
    TestClass* ptrObj = (TestClass*)ClassFactory::getInstance().getClassByName("TestClass");
    ptrObj->m_print();
    std::cout<<ptrObj->i<<std::endl;
    TestClassA* ptrObjA = (TestClassA*)ClassFactory::getInstance().getClassByName("TestClassA");
    ptrObjA->m_print();
    std::cout<<ptrObjA->i<<std::endl;
}