#include "Factory.h"

int main() {
    std::cout << "Factory Pattern\n" << std::endl;

    AbstractProduct* product = nullptr;
    AbstractFactory* factory = nullptr;

    factory = new BasketballFactory();
    product = factory->getProduct();
    std::cout << std::endl;

    factory = new FootballFactory();
    product = factory->getProduct();
    std::cout << std::endl;

    factory = new VolleyballFactory();
    product = factory->getProduct();
    std::cout << std::endl;

    return 0;
}