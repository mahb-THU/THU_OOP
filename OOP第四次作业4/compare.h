#pragma once
#include "abstract_compare.h"
#include "point.h"
using namespace std;
AbstractCompare<int>* get_compare_int(int type);
AbstractCompare<Point>* get_compare_point(int type);
class absractcompare1: public AbstractCompare<int> {
    bool compare(int a, int b);
};
class absractcompare2: public AbstractCompare<int> {
    bool compare(int a, int b);
};
class absractcompare3: public AbstractCompare<Point> {
    bool compare(Point a, Point b);
};
class absractcompare4: public AbstractCompare<Point> {
    bool compare(Point a, Point b);
};
bool absractcompare1::compare(int a, int b) {
    return a < b;
}
bool absractcompare2::compare(int a, int b) {
    int sum_a=0;
    int sum_b=0;
    int tmp_a=a;
    int tmp_b=b;
    while(tmp_a>0){
        sum_a+=tmp_a%10;
        tmp_a=tmp_a/10;
    }
    while(tmp_b>0){
        sum_b+=tmp_b%10;
        tmp_b=tmp_b/10;
    }
    if(sum_a==sum_b)
        return a<b;
    return sum_a<sum_b;
}
bool operator<(const Point &a, const Point &b) {
    if (a.x == b.x){
        return a.y < b.y;
    }else{
        return a.x < b.x;
    }
}
bool absractcompare3::compare(Point a, Point b) {
    return a < b;
}
bool absractcompare4::compare(Point a, Point b) {
    if(((a.x)*(a.x)+(a.y)*(a.y))==((b.x)*(b.x)+(b.y)*(b.y))){
        return a<b;
    }else{
        return ((a.x)*(a.x)+(a.y)*(a.y))<((b.x)*(b.x)+(b.y)*(b.y));
    }
}
AbstractCompare<int>* get_compare_int(int type){
    switch (type) {
        case 1:
            return new absractcompare1;
        case 2:
            return new absractcompare2;
        default:
            return nullptr;
    }
}
AbstractCompare<Point>* get_compare_point(int type){
    switch (type){
        case 3:
            return new absractcompare3;
        case 4:
            return new absractcompare4;
        default:
            return nullptr;
    }
}
