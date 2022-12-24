#include "AbstractFactory/AbstractFactory.h"

int main() {
    std::cout << "Abstract Factory Pattern\n" << std::endl;

    AbstractFactory*    factory = nullptr;
    AbstractShirt*      shirt   = nullptr;
    AbstractBall*       ball    = nullptr;

    factory = new BasketballFactory();
    shirt   = factory->getShirt();
    ball    = factory->getBall();
    std::cout << std::endl;

    factory = new FootballFactory();
    shirt   = factory->getShirt();
    ball    = factory->getBall();

    return 0;
}