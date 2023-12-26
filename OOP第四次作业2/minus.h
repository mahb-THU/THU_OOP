#pragma once
#include<iostream>
#include"operation.h"
using namespace std;
class minusoperation :public OperationNodeTwo{
    public:
    using OperationNodeTwo::OperationNodeTwo;
    virtual void UpdateValue() override;
    virtual void calc() override;
    virtual ~minusoperation();
};