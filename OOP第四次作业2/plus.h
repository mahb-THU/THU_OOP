#pragma once
#include<iostream>
#include"operation.h"
using namespace std;
class plusoperation :public  OperationNodeTwo{
    public:
    using OperationNodeTwo::OperationNodeTwo;
    virtual void UpdateValue() override;
    virtual void calc() override;
    virtual ~plusoperation();
};