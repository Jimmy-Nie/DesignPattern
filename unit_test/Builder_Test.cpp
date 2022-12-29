#include "CreationMode/Builder.h"
using namespace DP;

int main() {
    std::cout << "Builder Pattern\n" << std::endl;

    Meal package1;
    package1.addItem(new VegBurger);
    package1.addItem(new CocaCola);

    package1.showItem();
    std::cout << "The package 1 cost: " << package1.getCost() << std::endl;

    return 0;
}