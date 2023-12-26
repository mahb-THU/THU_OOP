#include<iostream>
#include"plus.h"
#include"operation.h"
using namespace std;
plusoperation::~plusoperation()=default;
void plusoperation::UpdateValue(){
    value_=input1->value()+input2->value();
}
void plusoperation::calc(){
    OperationNodeTwo::calc();
}