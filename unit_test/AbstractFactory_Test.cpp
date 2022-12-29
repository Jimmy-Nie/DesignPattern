#include "CreationMode/AbstractFactory.h"

using namespace DP;

int main() {
    std::cout << "Abstract Factory Pattern\n" << std::endl;

    auto pShapeFactory = FactoryProduct::getFactory(FactoryShape);
    auto pShapeRect = pShapeFactory->getShape(ShapeRect);
    pShapeRect->draw();

    auto pColorFactory = FactoryProduct::getFactory(FactoryColor);
    auto pColorBlue = pColorFactory->getColor(ColorBlue);
    pColorBlue->fill();

    std::cout << std::endl;

    return 0;
}
