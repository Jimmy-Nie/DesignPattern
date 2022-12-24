//
// Created by Administrator on 2021/6/23.
//
#include "Observer/Observer.h"

int main() {
    Student John1("John1");
    Student John2("John2");

    Teacher Lily("Lily");
    Teacher Lucy("Lucy");

    Principal pc("Jimmy");
    
    pc.attach("student", &John1);
    pc.attach("student", &John2);

    pc.attach("teacher", &Lily);
    pc.attach("teacher", &Lucy);
    
    pc.notify("teacher");
    pc.notify("student");

    pc.detach("teacher", &Lily);
    pc.detach("teacher", &Lucy);
    pc.notify("teacher");

}
