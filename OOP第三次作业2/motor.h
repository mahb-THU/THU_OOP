#pragma once
#include<iostream>
#include<string>
#include"vehicle.h"
using namespace std;
class Motor : public Vehicle{
    public:
    Motor(int _num,string _name);
    void describe();
    void sell();
};
