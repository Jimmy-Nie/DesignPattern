#include "Builder/Builder.h"

int main() {
    std::cout << "Builder Pattern\n" << std::endl;

    House* house;
    AbstractBuilder* builder;
    auto director = new Director();

    builder = new concreteBuilderA();
    director->setBuilder(builder);
    house = director->buildHouse();
    house->printHouse();

    std::cout << std::endl;

    builder = new concreteBuilderB();
    director->setBuilder(builder);
    house = director->buildHouse();
    house->printHouse();

    return 0;
}