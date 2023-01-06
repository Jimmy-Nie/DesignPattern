#include "Composite.h"

int main() {
    auto CEO = new Employee("Jimmy", "CEO", 5e6);
    auto DEV = new Employee("Bai", "CTO", 1e6);
    auto Market = new Employee("Hu", "CMO", 5e5);

    CEO->add(DEV);
    CEO->add(Market);

    DEV->add( new Employee("Le", "develop", 4e5) );
    DEV->add( new Employee("Tian", "develop", 3e5) );

    Market->add( new Employee("Yu", "market", 5e5) );
    Market->add( new Employee("Yang", "market", 4e5) );

    std::cout << CEO->toString() << std::endl << std::endl;
    for(auto& header : CEO->getSubordinate()) {
        std::cout << header->toString() << std::endl;
        for(auto& employee : header->getSubordinate())
            std::cout << employee->toString() << std::endl;

        std::cout << std::endl;
    }

    return 0;
}