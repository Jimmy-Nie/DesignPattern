#include "Factory/Factory.h"

using namespace DP;

int main() {
    std::cout << "Factory Pattern\n" << std::endl;

    auto pRect = ShapeFactory::getShape(ShapeRect);
    pRect->draw();

    auto pCircle = ShapeFactory::getShape(ShapeCircle);
    pCircle->draw();

    std::cout << std::endl;

    return 0;
}
