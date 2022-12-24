/**
 * @brief: 命令模式
 *          将一个请求封装成一个对象，从而使得可以使用不同的请求对客户进行参数化
 *          对请求进行排队或者记录请求日志，支持撤销操作
 *
 * @author: jimmy
 * @date: 2021-06-28
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/**
 * @brief: 执行者类
 */
class Executor{
public:
    void play() {
        std::cout<<"Execute play cmd!!"<<std::endl;
    }
    void sleep() {
        std::cout<<"Execute sleep cmd!!"<<std::endl;
    }
};

/**
 * @brief: 抽象的命令，包含执行者，具体的执行由子类实现
 */
class Command {
public:
    Command(Executor e) : executor(e) {}
    virtual void execute() = 0;
    virtual std::string getName() = 0;

protected:
    Executor executor;
};

class CmdPlay : public Command {
public:
    CmdPlay(Executor e) : Command(e) {}

    void execute() override {
        executor.play();
    }
    std::string getName() {return name_;}

private:
    std::string name_ = "CmdPlay";
};

class CmdSleep : public Command {
public:
    CmdSleep(Executor e) : Command(e) {}

    void execute() override {
        executor.sleep();
    }

    std::string getName() {return name_;}

private:
    std::string name_ = "CmdSleep";
};

/**
 * @brief: 服务者类
 */
class Server {
public:
    void setCmdOrder(Command* cmd) {
        auto it = std::find(cmds.begin(), cmds.end(), cmd);
        if(it == cmds.end())
            cmds.emplace_back(cmd);
        else
            std::cout << "There was alreay has the same command: " << cmd->getName() << std::endl;
    }

    void cancelCmdOrder(Command* cmd) {
        auto it = std::find(cmds.begin(), cmds.end(), cmd);
        if(it != cmds.end())
            cmds.erase(it);
        else
            std::cout<<"There was no cmd:xxx"<<std::endl;
    }

    void notify() {
        for(auto &cmd : cmds)
            cmd->execute();
    };

private:
    std::vector<Command*> cmds;
};