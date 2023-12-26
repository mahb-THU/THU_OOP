#pragma once
#include<iostream>
using namespace std;
template<typename T> class my_ptr{
private:
    T* ptr;
    //申请一块静态内存
    static T rubbish;
public:
    //构造函数
    my_ptr(T* test=nullptr);
    //析构函数
    ~my_ptr();
    //禁用拷贝构造函数
    my_ptr(const my_ptr& ptr_copy);
    //禁用拷贝赋值运算符
    my_ptr& operator=(const my_ptr &ptr_copy);
    //实现移动构造函数
    my_ptr(my_ptr && ptr_move);
    //实现移动赋值运算符
    my_ptr& operator=(my_ptr&& ptr_move);
    //重载“*”运算符并保护空指针
    T& operator*()const;
    //重载“->”运算符并保护空指针
    T* operator->()const;
};

template<typename T>
T my_ptr<T>::rubbish = T();

//智能指针构造函数
template<typename T>
my_ptr<T>::my_ptr(T* test){
    ptr=test;
    cout<<"my_ptr constructed."<<endl;
}
//智能指针析构函数
template<typename T>
my_ptr<T>::~my_ptr (){
    delete ptr;
    ptr=nullptr;
    cout<<"my_ptr destructed."<<endl;
}
//禁用拷贝构造函数
template<typename T>
my_ptr<T>::my_ptr(const my_ptr& ptr_copy){
    cout<<"Copying of my_ptr is forbidden!"<<endl;
    cout<<"my_ptr constructed."<<endl;
    ptr=nullptr;
}
//禁用拷贝赋值运算符
template<typename T>
my_ptr<T>& my_ptr<T>::operator=(const my_ptr& ptr_copy){
    cout<<"Copying of my_ptr is forbidden!"<<endl;
    cout<<"my_ptr updated."<<endl;
    return *this;
}
//实现移动构造函数
template<typename T>
my_ptr<T>::my_ptr(my_ptr && ptr_move){
    cout<<"my_ptr constructed."<<endl;
    ptr=ptr_move.ptr;
    ptr_move.ptr=nullptr;
}
//实现移动赋值运算符
template<typename T>
my_ptr<T>& my_ptr<T>::operator=(my_ptr && ptr_move){
    if(this!=& ptr_move){
        cout<<"my_ptr updated."<<endl;
        delete ptr;
        ptr=ptr_move.ptr;
        ptr_move.ptr=nullptr;
    }
    return *this;
}
//重载“*”运算符并保护空指针
template<typename T>
T& my_ptr<T>::operator*()const{
    if(ptr==nullptr){
        cout<<"Do not attempt to read a nullptr!"<<endl;
        return rubbish;
    }else{
        return *ptr;
    }
}
//重载“->”运算符并保护空指针
template<typename T>
T* my_ptr<T>::operator->()const{
    if(ptr==nullptr){
        cout<<"Do not attempt to read a nullptr!"<<endl;
        return &rubbish;
    }else{
        return ptr;
    }
}

