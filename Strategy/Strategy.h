#pragma once

#include <iostream>
#include <string>

class CashSuper {
public:
    virtual double acceptCash(double price) = 0;
};

class CashNormal : public CashSuper {
public:
    double acceptCash(double price) override {
        std::cout << "Normal Price: " << price << std::endl;
        return price;
    }
};

class CashRebate : public CashSuper {
public:
    CashRebate(double rebate) {
        rebate_ = rebate;
    }

    double acceptCash(double price) override {
        std::cout << "Rebate Price: " << price*rebate_ << std::endl;
        return price*rebate_;
    }

private:
    double rebate_ = 0.0F;
};

class CashReturn : public CashSuper {
public:
    CashReturn(double condition, double ret) {
        condition_ = condition;
        ret_ = ret;
    }

    double acceptCash(double price) override {
        int multiple = static_cast<int>(price) / static_cast<int>(condition_);
        std::cout << "Rebate Price: " << price - multiple*ret_ << std::endl;
        return (price - multiple*ret_);
    }

private:
    double condition_ = 0.0F;
    double ret_ = 0.0F;
};


class CashFactory {
public:
    static CashSuper* creatCashAccept(int type) {
        CashSuper* cc = nullptr;

        switch (type) {
            case 0:
                cc = new CashNormal();
                break;
            case 1:
                cc = new CashRebate(0.8);
                break;
            case 2:
                cc = new CashReturn(200, 100);
                break;
        }
        return cc;
    }
};