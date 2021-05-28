#include "Prototype.h"

int main() {
    std::cout << "Prototype Pattern\n" << std::endl;

    auto jimmy = new ConcretePrototype(1, "Jimmy");
    jimmy->print();
    std::cout << std::endl;

    auto lucy = jimmy->clone();
    lucy->setName("Lucy");
    lucy->setIdNum(2);
    lucy->print();

    return 0;
}