#include "demo/person.h"
#include <iostream>

namespace demo {
    Person::Person(const std::string &name, int age) : name_(name), age_(age) {
    }

    void Person::sayHello() const {
        std::cout << "Hi, my name is " << name_
                << " and I am " << age_ << " years old." << std::endl;
    }

    void Person::setAge(int age) {
        age_ = age;
    }

    int Person::getAge() const {
        return age_;
    }
} // namespace demo
