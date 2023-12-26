#pragma once
#include<iostream>
using namespace std;
class LevelStrategy{
public:
    int level; 
    virtual int getlevel()=0; 
};
class P1LStrategy : public LevelStrategy{
public:
    P1LStrategy();
    int getlevel();
};
class P2LStrategy : public LevelStrategy{
public:
    P2LStrategy();
    int getlevel();
};
class P3LStrategy : public LevelStrategy{
public:
    P3LStrategy();
    int getlevel();
};