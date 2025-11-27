#include "demo/person.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    demo::Person p("Alice22", 25);
    p.sayHello();
    p.setAge(300);
    p.sayHello();
    std::cout << "dddddd" << std::endl;
    return 0;
}
