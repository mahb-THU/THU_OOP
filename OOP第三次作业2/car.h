#pragma once
#include<iostream>
#include<string>
#include"vehicle.h"
using namespace std; 
class Car : public Vehicle {
    public:
    Car(int _num,string _name);
    void describe();
};
