#include<iostream>
#include<vector>
#include"Rack.h"
using namespace std;
//subtask 1
Rack& Rack::operator +=(int a){
    rack.push_back(a);
    return *this;
}
Rack& Rack::operator +=(Rack& a){
    int tmp = a.rack.size();
    for(int i=0;i<tmp;i++){
        rack.push_back(a.rack[i]);
    }
    return *this;
}
ostream& operator<< (ostream& out, const Rack& a) {
    for(int i=0;i<a.rack.size();i++){
        out<<" "<<a.rack[i];
    }
    return out;
}
//subtask 2 
Rack::Rack(int a){
    rack.push_back(a);
}
Rack Rack::operator,(Rack B){
    Rack result;
    for(int i=0;i<rack.size();i++){
        result.rack.push_back(rack[i]);
    }
    for(int i=0;i<B.rack.size();i++){
        result.rack.push_back(B.rack[i]);
    }
    return result;
}
Rack operator,(int a,Rack A){
    Rack result(A);
    result.rack.insert(result.rack.begin(),a);
    return result;
}
bool Rack::operator<(const Rack& a)const{
    return (this->rack.size()<a.rack.size());
}
bool Rack::operator>(const Rack& a)const{
    return (this->rack.size()>a.rack.size());
}
bool Rack::operator==(const Rack& a)const{
    return (this->rack.size()==a.rack.size());
}
Rack Rack::operator&(Rack&a){
    Rack result;
    for(int i=0;i<rack.size();i++){
        for(int j=0;j<a.rack.size();j++){
            if(rack[i]==a.rack[j]){
                int count=0;
                for(int k=0;k<result.rack.size();k++){
                    if(rack[i]==result.rack[k]){
                        count++;
                        break;
                    }
                }
                if(count==0){
                    result.rack.push_back(rack[i]);
                }
            }
        }
    }
    return result;
}
//subtask 3
int Rack::operator()(int a)const{
    int count=0;
    for(int i=0;i<rack.size();i++){
        if(rack[i]==a){
            count++;
        }
    }
    return count;
}
//前缀“~”
Rack Rack::operator~(){
    int mid[rack.size()]={0};
    for(int i=0;i<rack.size();i++){
        mid[i]=rack[rack.size()-1-i];
    }
    for(int i=0;i<rack.size();i++){
        rack[i]=mid[i];
    }
    return *this;
}
//后缀
Rack Rack::operator--(int){
    rack.pop_back();
    return *this;
}
//前缀
Rack Rack::operator--(){
    rack.erase(rack.begin());
    return *this;
}


