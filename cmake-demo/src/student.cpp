//
// Created by dataexa on 2025/11/26.
//

#include <iostream>
using namespace std;

class Student {
private:
    string name_;
    int age_;

public:
    // Student( string name, int age) { // 值传递 ，函数接收 name 参数时会创建一个副本（copy）
    Student(const string &name, const int age) { // 引用传递
        this->name_ = name;
        this->age_ = age;
    }

    void introduce() const {
        cout << "我的名字是：" << name_ << "，我今年" << age_ << "岁。" << endl;
    }


    void setAge(const int age) {
        age_ = age;
    }

    int getAge() const {
        return age_;
    }
};

int main() {
    Student student("张三", 18);
    student.introduce();
    return 0;
}
