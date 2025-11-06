#include "demo/person.h"

int main(int argc, char const *argv[])
{
    demo::Person p("Alice22", 25);
    p.sayHello();
    p.setAge(300);
    p.sayHello();
    return 0;
}
