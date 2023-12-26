#include<iostream>
#include<vector>
using namespace std;
template<typename T,int n>class MultiDimArray{
private:
    vector<MultiDimArray<T,n-1>> data;
public:
    MultiDimArray(vector<int> a){
        int dim = a[0];
        a.erase(a.begin());
        for(int i=0;i<dim;i++){
            data.emplace_back(MultiDimArray<T, n-1>(a));
        }
    }
    ~MultiDimArray(){}
    MultiDimArray(const MultiDimArray& a)=default;
    MultiDimArray(MultiDimArray && a)=default;
    MultiDimArray<T,n-1>& operator[](int m){
        return data[m];
    }
    MultiDimArray<T,n>& operator=(const MultiDimArray& other){
        if(this!=&other){
            data.clear();
            data.shrink_to_fit();
            for(int i=0;i<other.data.size();i++){
                data.emplace_back(other.data[i]);
            }
        } 
        return *this;  
    }
    MultiDimArray<T,n>& operator=(MultiDimArray && other){
        if(this!=&other){
            data.clear();
            data.shrink_to_fit();
            this->data=std::move(other.data);
        }
        return *this;
    }
};
template<typename T>class MultiDimArray<T,1>{
private:
    vector<T> data;
public:
    MultiDimArray(vector<int> a){
        for(int i=0;i<a[0];i++){
            data.emplace_back(T());
        }
    }
    ~MultiDimArray(){
        data.clear();
        data.shrink_to_fit();
    }
    T& operator[](int m){
        return data[m];
    }
};

