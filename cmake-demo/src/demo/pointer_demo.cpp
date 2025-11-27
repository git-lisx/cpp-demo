#include <iostream>
#include <string>
#include <memory>

// 定义一个简单的类
class Student {
public:
    std::string name_;
    int score_;

public:
    Student(const std::string &name, int score)
        : name_(name), score_(score) {
    }

    void display() const {
        std::cout << "学生 " << name_ << " 的分数是: " << score_ << std::endl;
    }

    void updateScore(int newScore) {
        score_ = newScore;
        std::cout << name_ << " 的分数已更新为: " << score_ << std::endl;
    }
};


int main() {
    // 栈上分配-推荐（约等于自动释放内存）
    Student s12("张三2", 952);
    s12.display();
    s12.name_ = "张三1";


    std::cout << "=== 1. 普通指针的使用 ===" << std::endl;
    Student *s1 = new Student("张三", 95);
    s1->display(); // 使用箭头操作符访问成员函数
    s1->updateScore(98); // 使用箭头操作符修改数据
    delete s1; // 记得释放内存
    std::cout << std::endl;

    std::cout << "=== 2. 智能指针的使用（自动释放内存）推荐 ===" << std::endl;
    auto s2 = std::make_unique<Student>("李四", 88);
    s2->display(); // 智能指针也使用箭头操作符
    s2->updateScore(92); // 不需要手动释放内存
    s2->name_ = "王五";
    std::cout << std::endl;

    std::cout << "=== 3. 指针数组的使用 ===" << std::endl;
    // 使用智能指针数组
    std::unique_ptr<Student> students[] = {
        std::make_unique<Student>("赵六", 85),
        std::make_unique<Student>("钱七", 91)
    };

    for (const auto &student: students) {
        student->display(); // 使用箭头操作符遍历访问
    }

    return 0;
}
