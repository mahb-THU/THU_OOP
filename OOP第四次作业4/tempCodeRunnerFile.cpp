#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> test;
    for(int i=0;i<3;i++){
        cin>>test[i];
    }
    cout<<test.begin()-test.end();
    return 0;
}
