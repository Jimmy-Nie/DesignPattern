#include "Singleton/Singleton.h"
#include <string>
#include <thread>
#include <chrono>

void threadA() {
    auto obj = Singleton::getInstance();
    std::cout << "The address: " << obj << std::endl;

    for(int i=0; i>-10; i--) {
        std::cout << std::hex << "PID: 0x" << std::this_thread::get_id() << std::endl << std::endl;
        obj->getNum();
        obj->setNum(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(1200));
    }
}

void threadB() {
    auto obj = Singleton::getInstance();
    std::cout << "The address: " << obj << std::endl;

    for(int i=0; i<10; i++) {
        obj->setNum(i);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << std::hex << "PID: 0x" << std::this_thread::get_id() << std::endl << std::endl;
        obj->getNum();
    }
}

int main() {
    std::thread first(threadA);
    std::thread second(threadB);

    first.join();
    second.join();

    return 0;
}