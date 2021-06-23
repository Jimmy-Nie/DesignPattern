#include <iostream>
#include <string>
#include <functional>

std::function<bool(int ,int)> fun;

bool compareOrdinary(int a, int b) {
    return (a > b);
}

auto compareLambda = [] (int a, int b) -> bool {return a>b;};

class CompareClass {
public:
    bool compareMember(int a, int b) {return a>b;}
    static bool compareMemberStatic(int a, int b) {return a>b;}
};

int main() {
    fun = compareOrdinary;
    std::cout << std::boolalpha << "compareOrdinary: " << fun(2,3) << std::endl;

    fun = compareLambda;
    std::cout << std::boolalpha << "compareLambda: " << fun(2,3) << std::endl;

    fun = CompareClass::compareMemberStatic;
    std::cout << std::boolalpha << "compareMemberStatic: " << fun(2,3) << std::endl;

    fun = std::bind(&CompareClass::compareMember, CompareClass(), std::placeholders::_2, std::placeholders::_1);
    std::cout << std::boolalpha << "compareMember: " << fun(2,3) << std::endl;

    return false;
}