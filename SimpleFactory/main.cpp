/**
 * Author: Jimmy
 * Date: 2021-05-22
 * Description: The design pattern of Simple Factory
 */

#include "SimpleFactory.h"

int main() {
    std::cout << "Simple Factory pattern ...\n" <<std::endl;

    Factory* fac = new Factory();
    AbstractSportProduct* product = nullptr;

    product = fac->getSportProduct("Basketball");
    std::cout << std::endl;

    product = fac->getSportProduct("Football");
    std::cout << std::endl;

    product = fac->getSportProduct("Volleyball");
    std::cout << std::endl;

    return 0;
}