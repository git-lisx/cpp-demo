#ifndef PERSON_H
#define PERSON_H

#include <string>

namespace demo
{

    class Person
    {
    public:
        Person(const std::string &name, int age);
        void sayHello() const;
        void setAge(int age);
        int getAge() const;

    private:
        std::string name_;
        int age_;
    };

} // namespace demo

#endif // PERSON_H
