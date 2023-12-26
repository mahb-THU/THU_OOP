#include <iostream>
#include <list>
#include <vector>
#include "compare.h"
#include "sortlevel.h"
using namespace std;
Compare<vector<int>> make_comp(list<sort_level> sortlevels){
    Compare<vector<int>> cmp;
    for(auto it=sortlevels.begin();it!=sortlevels.end();it++){
        if((*it).order==0){
            cmp.data.push_back([=](vector<int> a,vector<int> b){return a[(*it).column-1]<b[(*it).column-1];});
        }
        if((*it).order==1){
            cmp.data.push_back([=](vector<int> a,vector<int> b){return a[(*it).column-1]>b[(*it).column-1];});
        }
    }
    return cmp;
}
