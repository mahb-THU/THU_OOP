#pragma once
#include<vector>
#include<iostream>
using namespace std;
class Rack{
    private:
    vector<int> rack;
    public:
    Rack()=default;
    Rack(int);
    ~Rack()=default;
    //subtask 1
    Rack& operator +=(int);
    Rack& operator +=(Rack&);
    friend ostream& operator<<(ostream&,const Rack&);
    //subtask 2
    friend Rack operator,(int ,Rack);
    Rack operator,(Rack);
    bool operator<(const Rack&)const;
    bool operator>(const Rack&)const;
    bool operator==(const Rack&)const;
    Rack operator&(Rack&);
    //subtask 3
    int operator()(int a)const;
    Rack operator~();
    //前缀
    Rack operator--();
    //后缀
    Rack operator--(int);
};
