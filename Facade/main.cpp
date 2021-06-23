//
// Created by Administrator on 2021/6/23.
//

#include "Facade.h"

int main() {
    auto pLinux = new Linux();
    pLinux->init();
    pLinux->display();

    return 0;
}