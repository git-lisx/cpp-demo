#include <iostream>
#include <memory>
#include <vector>
#include <string>

// 定义接口（抽象基类）
class Animal {
public:
    // 纯虚函数，相当于Java中的接口方法
    virtual void makeSound() const = 0;
    virtual void move() const = 0;
    
    // 虚析构函数确保正确析构派生类对象
    virtual ~Animal() = default;
};

// 实现类 Dog
class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Woof! Woof!" << std::endl;
    }
    
    void move() const override {
        std::cout << "Dog is running on four legs" << std::endl;
    }
};

// 实现类 Bird
class Bird : public Animal {
public:
    void makeSound() const override {
        std::cout << "Tweet! Tweet!" << std::endl;
    }
    
    void move() const override {
        std::cout << "Bird is flying in the sky" << std::endl;
    }
};

// 实现类 Fish
class Fish : public Animal {
public:
    void makeSound() const override {
        std::cout << "Blub! Blub!" << std::endl;
    }
    
    void move() const override {
        std::cout << "Fish is swimming in water" << std::endl;
    }
};

int main() {
    // 创建不同的动物对象
    Dog dog;
    Bird bird;
    Fish fish;
    
    // 使用基类指针指向不同实现类的对象，体现多态性
    std::vector<Animal*> animals;
    animals.push_back(&dog);
    animals.push_back(&bird);
    animals.push_back(&fish);
    
    std::cout << "=== 通过多态方式调用 ===" << std::endl;
    for (const auto& animal : animals) {
        animal->makeSound();
        animal->move();
        std::cout << "---" << std::endl;
    }
    
    std::cout << "\n=== 直接调用 ===" << std::endl;
    dog.makeSound();
    dog.move();
    
    bird.makeSound();
    bird.move();
    
    fish.makeSound();
    fish.move();
    
    return 0;
}