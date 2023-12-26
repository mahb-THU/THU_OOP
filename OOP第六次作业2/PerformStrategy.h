#pragma once
#include<iostream>
using namespace std;
class PerformStrategy{
public:  
    int grade;
    double perform;
    PerformStrategy();  
    PerformStrategy(double per);
    virtual int getgrade()=0;
    virtual double getperform()=0;
};
class sPerformStrategy : public PerformStrategy{
public:
    sPerformStrategy(double per);
    int getgrade();
    double getperform();
};
class mPerformStrategy : public PerformStrategy{
public:
    mPerformStrategy(double per);
    int getgrade();
    double getperform();
};
class lPerformStrategy : public PerformStrategy{
public:
    lPerformStrategy(double per);
    int getgrade();
    double getperform();
};