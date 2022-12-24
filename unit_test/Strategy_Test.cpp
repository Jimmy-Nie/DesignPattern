#include "Strategy/Strategy.h"

int main() {
    CashSuper* cash = nullptr;
    cash = CashFactory::creatCashAccept(0);
    cash->acceptCash(500);
    cash = CashFactory::creatCashAccept(1);
    cash->acceptCash(500);
    cash = CashFactory::creatCashAccept(2);
    cash->acceptCash(500);

    return 0;
}