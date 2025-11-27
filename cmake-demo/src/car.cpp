//
// Created by dataexa on 2025/11/26.
//

#include "../include/car.h"
#include <iostream>
using namespace std;

Car::Car(const std::string &brand, const int speed) {
    this->brand_ = brand;
    this->speed_ = speed;
}


void Car::run() const {
    cout << brand_ << "汽车正在以" << speed_ << "的时速行驶" << endl;
}


