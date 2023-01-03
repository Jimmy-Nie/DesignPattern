#include "StructMode/Bridge.h"

using namespace DP;

int main() {
    std::cout << "Bridge Pattern\n" << std::endl;

    Circle circle1(10, 1, 2, new RedCircle());
    circle1.draw();

    std::cout << std::endl;

    return 0;
}