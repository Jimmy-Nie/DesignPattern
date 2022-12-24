#include "Decorator/Decorator.h"

int main() {
    auto jimmy = new Person("Jimmy");

    std::cout << "第一种装扮: " << std::endl;
    auto tshirt = new Tshirt();
    auto trouser = new Trouser();

    tshirt->decorate(jimmy);
    trouser->decorate(tshirt);  ///里氏替换原则（凡是可用父类的地方均可由子类替换）
    trouser->show();            ///先调用自身的show，然后调用tshirt的show，最后调用person的show

    std::cout  << std::endl << "第二种装扮: " << std::endl;
    auto suit = new Suit();
    auto leather_shoes = new LeatherShoes();

    suit->decorate(jimmy);
    leather_shoes->decorate(suit);      ///里氏替换原则（凡是可用父类的地方均可由子类替换）
    leather_shoes->show();              ///先调用自身的show，然后调用suit的show，最后调用person的show


    return 0;
}