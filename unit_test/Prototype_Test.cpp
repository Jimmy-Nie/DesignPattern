#include "CreationMode/Prototype.h"

using namespace DP;

int main() {
    auto p_cache = new ShapeCache();
    p_cache->loadCache();

    Shape *p_rect = p_cache->getShape(1);
    std:: cout << "Type: " << p_rect->getType() << std::endl;
    std::cout << "ID: " << p_rect->getID() << std::endl;
    p_rect->draw();

    return 0;
}