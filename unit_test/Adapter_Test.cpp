#include "Adapter/Adapter.h"

int main() {
    std::cout << "Adapter Pattern\n" << std::endl;

    Communication* com = new NetworkAdapter();
    com->sendMsg();
    std::cout << std::endl;
    com->recvMsg();

    return 0;
}