#include<iostream>
using namespace std;
class Matrix {
private:
    int** elem;
    int col, row;
    
public:
    Matrix();
    Matrix(int _row, int _col);
    ~Matrix();

    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    Matrix operator*(const int);
    Matrix operator*(const Matrix&);
    friend Matrix transpose(const Matrix&);
    int* operator[](int) const;
    friend ostream& operator<<(ostream&, const Matrix&);
    friend istream& operator>>(istream&, Matrix&);
};

