//
// Created by Administrator on 2021/6/23.
//
#include "Template/Template.h"

int main() {
    Wifi* p_wifi = new Ubuntu();
    p_wifi->restartWifi();
    p_wifi->setSsidPsk("Ubuntu", "Linux");

    p_wifi = new CentOS();
    p_wifi->restartWifi();
    p_wifi->setSsidPsk("CentOS", "Linux");

    return 0;
}
