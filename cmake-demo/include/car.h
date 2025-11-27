//
// Created by dataexa on 2025/11/26.
//

#ifndef DEMO_PROJECT_CAR_H
#define DEMO_PROJECT_CAR_H
#include <string>


// #include <string>
class Car {

private:
    std::string brand_; // 品牌
    int speed_;

public:
    Car(const std::string &brand, int speed);

    void run() const;

};

#endif //DEMO_PROJECT_CAR_H