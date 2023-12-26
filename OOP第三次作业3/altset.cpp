#include <iostream>
#include <utility>
#include <vector>
#include "altset.h"
using namespace std;
Altset::Altset(const char *data, int len){
    for(int i=len-1;i>=0;i--){
        gene.push_back(data[i]);
    }
}
Altset&Altset::operator = (const Altset &altset){
    if(this!=&altset){
        for(int i=0;i<altset.gene.size();i++){
            gene.push_back(altset.gene[i]);
        }
    }
    return *this;
}
Altset&Altset::operator = (Altset &&altset){
    if(this!=&altset){
        this->gene=altset.gene;
    }
    altset.gene.clear();
    altset.gene.shrink_to_fit();
    return *this;
}
void Altset::inverse(int index){
    if(gene[index]=='1'){
        gene[index]='0';
    }
    else if(gene[index]=='0'){
        gene[index]='1';
    }

}
void Altset::append(int value){
    gene.push_back(value+'0');
}
bool Altset::get(int index) const{
    if(gene[index]=='1'){
        return true;
    }else{
        return false;
    }
}
bool Altset::empty() const{
    if(gene.size()==0){
        return true;
    }else{
        return false;
    }
}
int Altset::count() const{
    int num=0;
    for(int i=0;i<gene.size();i++){
        if(gene[i]=='1'){
            num++;
        }
    }
    return num;
}