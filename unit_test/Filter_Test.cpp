//
// Created by Jimmy on 2023/1/5 0005.
//

#include "Filter.h"

using namespace DP;

void printPersons(const std::list<Person>& persons) {
    for(auto& it : persons) {
        std::cout << "\t Name: " << it.getName() << std::endl;
        std::cout << "\t Sex: " << ((it.getGender() == Person::Male) ? "Male" : "Female") << std::endl;
        std::cout << "\t Married: " << ((Person::Married == it.getMaritalStatus()) ? "Yes" : "No") << std::endl;
        std::cout << "  ------" << std::endl;
    }
}

int main() {
    std::list<Person> persons;
    persons.emplace_back(Person("Jimmy", Person::Male, Person::Married));
    persons.emplace_back(Person("Emily", Person::Female, Person::Married));
    persons.emplace_back(Person("Hu", Person::Male, Person::UnMarried));
    persons.emplace_back(Person("Bai", Person::Male, Person::UnMarried));
    persons.emplace_back(Person("Yu", Person::Female, Person::UnMarried));
    persons.emplace_back(Person("Yang", Person::Female, Person::UnMarried));

    auto male_filter = new MaleFilter();
    auto female_filter = new FemaleFilter();
    auto single_filter = new SingleFilter();
    auto single_male_filter = new AddFilter(male_filter, single_filter);
    auto single_or_female_filter = new OrFilter(female_filter, single_filter);

    std::cout << "============================\nMale:\n";
    printPersons(male_filter->meetFilter(persons));

    std::cout << "============================\nFemale:\n";
    printPersons(female_filter->meetFilter(persons));

    std::cout << "============================\nSingle:\n";
    printPersons(single_filter->meetFilter(persons));

    std::cout << "============================\nSingle and Male:\n";
    printPersons(single_male_filter->meetFilter(persons));

    std::cout << "============================\nSingle OR Female:\n";
    printPersons(single_or_female_filter->meetFilter(persons));


    return 0;
}