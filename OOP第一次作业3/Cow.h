#pragma once
#include<string>
#include<iostream>
class Cow{
	public:
		int lowlimit;
		int highlimit;
	    int milk;
	    std::string name;
		Cow(std::string name="",int l=0,int u=0,int m=0){
			this->name=name;
			lowlimit=l;
			highlimit=u;
			milk=m;
		}
}; 

