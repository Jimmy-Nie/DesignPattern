#include "Command/Command.h"

int main() {
    ///1. 建设指令实例
    auto executor = new Executor();
    Command* start = new CmdPlay(*executor);
    Command* stop = new CmdSleep(*executor);

    ///2. 客户端操作
    auto server = new Server();
    server->setCmdOrder(start);
    server->setCmdOrder(stop);
    server->setCmdOrder(start);
    server->notify();

    server->cancelCmdOrder(start);
    server->notify();

    return 0;
}