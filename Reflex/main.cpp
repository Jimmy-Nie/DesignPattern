#include "Reflex.h"

class TestClassA {
public:
    void print() {
        std::cout << "TestClassA !!!!" << std::endl;
    }

    int i = 100;
};

class TestClassB {
public:
    void print() {
        std::cout << "TestClassB !!!!" << std::endl;
    }
};

REGISTER(TestClassA);
REGISTER(TestClassB);

int main() {
    TestClassA* testA = (TestClassA*)Factory::getInstance().getClassByName("TestClassA");
    if(testA)
        testA->print();

    TestClassB* testB = reinterpret_cast<TestClassB*>(Factory::getInstance().getClassByName("TestClassB"));
    if(testB)
        testB->print();

    return 0;
}