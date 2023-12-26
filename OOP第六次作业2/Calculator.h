#pragma once
#include<iostream>
#include"LevelStrategy.h"
#include"PerformStrategy.h"
using namespace std;
class Calculator{
private:
   int l;
   int g;
   double p;
public:
   Calculator(LevelStrategy* m_levelStrategy,PerformStrategy* m_perfomStrategy);
   int get_base();
   int get_total(int base);
};
