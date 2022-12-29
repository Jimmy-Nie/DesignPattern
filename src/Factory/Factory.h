/**
 * @brief: 工厂 模式
 *          定义一个创建对象的接口，由客户端决定到底实例化哪一个类
 * @author: jimmy
 * @date: 2021-06-24
 */

#pragma once
#include <iostream>
#include <string>

namespace DP {

enum ShapeType{
    ShapeCircle,
    ShapeRect
};

class Shape {
public:
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    void draw() override { std::cout << "Circle Shape !!" << std::endl; }
};

class Rect : public Shape {
public:
    void draw() override { std::cout << "Rectangle Shape !!" << std::endl; }
};

class ShapeFactory {
public:
    static Shape* getShape(ShapeType type) {
        Shape* pShape = nullptr;
        switch(type) {
            case ShapeCircle:
                pShape = new Circle();
                break;
            case ShapeRect:
                pShape = new Rect();
                break;
            default:
                break;
        }
        return pShape;
    }
};
}