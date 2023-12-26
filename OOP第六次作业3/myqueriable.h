#include<iostream>
#include<functional>
#include<vector>
using namespace std;
template<typename T>
class myqueriable{
public:
    //数据区
    vector<T> data;
    //构造函数
    myqueriable(){};
    myqueriable(vector<T> init){};
    //模板函数,以一个vector为参数,返回值为对应的MyQueriable
    friend myqueriable from(vector<T> init);
    //求和
    T sum();
    //求长度
    int size();
    //重载数组下标访问功能
    T operator[](int num);
    myqueriable where(function<bool(T)> func);
    myqueriable apply(function<T(T)> func);
    ~myqueriable(){};
};
template<typename T>
myqueriable<T> from(vector<T> init){
    myqueriable<T> que; 
    que.data.clear();
    que.data.shrink_to_fit();
    for(int i=0;i<init.size();i++){
        que.data.push_back(init[i]);
    }
    return que; 
}
template<typename T>
T myqueriable<T>::sum(){
    T _sum=0;
    for(int i=0;i<data.size();i++){
        _sum+=data[i];
    }
    return _sum;
}
template<typename T>
int myqueriable<T>::size(){
    return data.size();
}
template<typename T>
T myqueriable<T>::operator[](int num){
    return data[num];
}
template<typename T>
myqueriable<T> myqueriable<T>::where(function<bool(T)> func){
    myqueriable<T> que;
    for(int i=0;i<data.size();i++){
        if(func(data[i])==true){
            que.data.push_back(data[i]);
        }
    }
    return que;
}
template<typename T>
myqueriable<T> myqueriable<T>::apply(function<T(T)> func){
    myqueriable<T> que;
    for(int i=0;i<data.size();i++){
        que.data.push_back(func(data[i]));
    }
    return que;
}