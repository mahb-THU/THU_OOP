#pragma once
#include<iostream>
#include<string>
#include"wheel.h"
#include"engine.h"
using namespace std;
class Vehicle{
    public:
    Engine e;
    Wheel w;
    Vehicle(int _num,string _name,string vehicle_name="vehicle");
    void describe();
};
