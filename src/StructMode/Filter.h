/**
 * 过滤器模式（Filter Pattern）或标准模式（Criteria Pattern）是一种设计模式，这种模式允许开发人员使用不同的标准来过滤一组对象，
 *      通过逻辑运算以解耦的方式把它们连接起来。这种类型的设计模式属于结构型模式，它结合多个标准来获得单一标准。
 */
#pragma once

#include <string>
#include <iostream>
#include <list>

namespace DP {
    class Person;
}
extern void printPersons(const std::list<DP::Person>& persons);

namespace DP {
/**
 * 我们将创建一个 Person 对象、Criteria 接口和实现了该接口的实体类，
 * 来过滤 Person 对象的列表。
 * CriteriaPatternDemo 类使用 Criteria 对象，基于各种标准和它们的结合来过滤 Person 对象的列表。
 */
class Person {
public:
    enum SexEnum {
        Male,
        Female
    };

    enum MaritalStatus {
        Married,
        UnMarried
    };

public:
    Person(std::string name, SexEnum gender, MaritalStatus marriage)
        : name_(std::move(name)), gender_(gender), marriage_(marriage) {}

    std::string getName() const {return name_;}
    SexEnum getGender() const {return gender_;}
    MaritalStatus getMaritalStatus() const {return marriage_;}

private:
    std::string name_;
    SexEnum gender_;
    MaritalStatus marriage_;
};

class Filter {
public:
    virtual std::list<Person> meetFilter(const std::list<Person>& person_list) = 0;
};

class MaleFilter : public Filter {
public:
    std::list<Person> meetFilter(const std::list<Person>& person_list) override {
        std::list<Person> filter_list;
        for(auto& it : person_list) {
            if(it.getGender() == Person::Male) {
                filter_list.emplace_back(it);
            }
        }

        return filter_list;
    }
};

class FemaleFilter : public Filter {
public:
    std::list<Person> meetFilter(const std::list<Person>& person_list) override {
        std::list<Person> filter_list;
        for(auto& it : person_list) {
            if(it.getGender() == Person::Female) {
                filter_list.emplace_back(it);
            }
        }

        return filter_list;
    }
};

class SingleFilter : public Filter {
public:
    std::list<Person> meetFilter(const std::list<Person>& person_list) override {
        std::list<Person> filter_list;
        for(auto& it : person_list) {
            if(it.getMaritalStatus() == Person::UnMarried) {
                filter_list.emplace_back(it);
            }
        }

        return filter_list;
    }
};

class AddFilter : public Filter {
public:
    AddFilter(Filter* first, Filter* second)
        : first_filter_(first), second_filter_(second) { }

    std::list<Person> meetFilter(const std::list<Person>& person_list) override {
        std::list<Person> first_persons = first_filter_->meetFilter(person_list);
        return second_filter_->meetFilter(first_persons);
    }

private:
    Filter* first_filter_ = nullptr;
    Filter* second_filter_ = nullptr;
};

class OrFilter : public Filter {
public:
    OrFilter(Filter* first, Filter* second)
            : first_filter_(first), second_filter_(second) { }

    std::list<Person> meetFilter(const std::list<Person>& person_list) override {
        std::list<Person> first_persons = first_filter_->meetFilter(person_list);
        std::list<Person> second_persons = second_filter_->meetFilter(person_list);
        std::list<Person> persons = first_persons;

        for(auto& it2 : second_persons) {
            bool found = false;
            for(auto& it1 : first_persons) {
                if(it1.getName() == it2.getName())
                    found = true;
            }

            if(!found)
                persons.emplace_back(it2);
        }

        return persons;
    }

private:
    Filter* first_filter_ = nullptr;
    Filter* second_filter_ = nullptr;
};
}
