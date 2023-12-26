#include<iostream>
#include<functional>
#include<initializer_list>
#include<vector>
using namespace std;
template<typename T>
class Compare{
public:
    vector<function<bool(T,T)>> data;
    Compare(){};
    Compare(initializer_list<function<bool(T,T)>> cmp){
        for(auto itm: cmp){
            data.push_back(itm);
        }
    }
    bool operator()(const T &a,const T &b)const{
        for(int i=0;i<data.size();i++){
            if(data[i](a,b)==true){
                return true;
            }
            if(data[i](b,a)==true){
                return false;
            }
        }
        return false;
    }
};
template<>
class Compare<vector<int>>{
public:
    vector<function<bool(vector<int>,vector<int>)>> data;
    Compare(){};
    Compare(initializer_list<function<bool(vector<int>,vector<int>)>> cmp){
        for(auto itm: cmp){
            data.push_back(itm);
        }
    }
    bool operator()(const vector<int> &a,const vector<int> &b)const{
        for(int i=0;i<data.size();i++){
            if(data[i](a,b)==true){
                return true;
            }
            if(data[i](b,a)==true){
                return false;
            }
        }
    }
};
