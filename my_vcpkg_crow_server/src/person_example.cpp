#include <iostream>
#include <string>

// 定义一个简单的Person类
class Person {
private:
    // 私有属性
    std::string name;
    int age;

public:
    // 构造函数
    Person(const std::string &personName, int personAge) : name(personName), age(personAge) {
    }

    Person() : name("aa"), age(1) {
    }

    // 公共方法 - 获取姓名
    std::string getName() const {
        return name;
    }

    // 公共方法 - 获取年龄
    int getAge() const {
        return age;
    }

    // 公共方法 - 设置姓名
    void setName(const std::string &personName) {
        name = personName;
    }

    // 公共方法 - 设置年龄
    void setAge(int personAge) {
        if (personAge >= 0) {
            age = personAge;
        }
    }

    // 公共方法 - 打印个人信息
    void introduce() const {
        std::cout << "你好，我的名字是" << name << "，今年" << age << "岁。" << std::endl;
    }
};

int main() {
    // 创建Person对象实例
    Person person("Alice", 25);

    // 调用方法
    person.introduce();

    // 修改属性
    person.setName("Bob");
    person.setAge(30);

    // 再次调用方法
    person.introduce();

    // 使用getter方法
    std::cout << "姓名: " << person.getName() << ", 年龄: " << person.getAge() << std::endl;

    Person person2 = Person();

    return 0;
}
