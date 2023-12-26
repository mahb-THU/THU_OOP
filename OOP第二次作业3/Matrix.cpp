#include"Matrix.h"
#include<iostream>
using namespace std;
Matrix::Matrix(){
    elem=new int*[30];
    for(int i=0;i<30;i++){
        elem[i]=new int[30];
    }
}
Matrix::Matrix(int _row, int _col){
    row=_row;
    col=_col;
}
Matrix::~Matrix(){
    for(int i=0;i<30;i++){//析构函数，释放内存
        delete[]elem[i];
    }
        delete[]elem;
    };
//矩阵相加
Matrix Matrix:: operator+(const Matrix& a){
    Matrix result;
    result.row=row;
    result.col=col;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            result.elem[i][j]=elem[i][j]+a.elem[i][j];
        }
    }
    return result;
}
//矩阵相减
Matrix Matrix:: operator-(const Matrix& a){
    Matrix result;
    result.row=row;
    result.col=col;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            result.elem[i][j]=elem[i][j]-a.elem[i][j];
        }
    }
    return result;
}
//数乘矩阵
Matrix Matrix::operator*(const int a){
    Matrix result;
    result.row=row;
    result.col=col;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            result.elem[i][j]=a*elem[i][j];
        }
    }
    return result;
}
//矩阵相乘
Matrix Matrix::operator*(const Matrix& a){
    Matrix result;
    result.row=row;
    result.col=a.col;
    for(int i=0;i<row;i++){
        for(int j=0;j<a.col;j++){
            result[i][j]=0;
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<a.col;j++){
            for(int k=0;k<col;k++){
                result.elem[i][j]+=(elem[i][k]*a.elem[k][j]);
            }
        }
    }
    return result;
}
//矩阵转置
Matrix transpose(const Matrix& a){
    Matrix result;
    result.row=a.col;
    result.col=a.row;
    for(int i=0;i<a.row;i++){
        for(int j=0;j<a.col;j++){
            result.elem[j][i]=a.elem[i][j];
        }
    }
    return result;
}
//数组下标重载
int* Matrix::operator[](int a) const{
    return elem[a];
}
//左移运算符重载
ostream& operator<<(ostream& out, const Matrix& a){
    for(int i=0;i<a.row;i++){
        for(int j=0;j<a.col;j++){
            out<<a.elem[i][j]<<" ";
        }
        out<<endl;
    }
    return out;
}
//右移运算符重载
istream& operator>>(istream& in , Matrix& a){
    int r,c;
    in>>r>>c;
    a.row=r;
    a.col=c; 
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            in>>a.elem[i][j]; 
        }
    }
    return in;
}
