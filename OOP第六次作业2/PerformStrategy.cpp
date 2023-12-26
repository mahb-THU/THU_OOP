#include"PerformStrategy.h"
#include<iostream>
using namespace std;
PerformStrategy::PerformStrategy(){}
PerformStrategy::PerformStrategy(double per){}
sPerformStrategy::sPerformStrategy(double per){
    perform=per;
    grade=1;
}
int sPerformStrategy::getgrade(){
    return grade;
}
double sPerformStrategy::getperform(){
    return perform;
}
mPerformStrategy::mPerformStrategy(double per){
    perform=per;
    grade=2;
}
int mPerformStrategy::getgrade(){
    return grade;
}
double mPerformStrategy::getperform(){
    return perform;
}
lPerformStrategy::lPerformStrategy(double per){
    perform=per;
    grade=3;
}
int lPerformStrategy::getgrade(){
    return grade;
}
double lPerformStrategy::getperform(){
    return perform;
}