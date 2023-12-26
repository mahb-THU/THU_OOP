#include<iostream>
#include"minus.h"
#include"operation.h"
using namespace std;
minusoperation::~minusoperation()=default;
void minusoperation::UpdateValue(){
    value_=input1->value()-input2->value();
}
void minusoperation::calc(){
    OperationNodeTwo::calc();
}