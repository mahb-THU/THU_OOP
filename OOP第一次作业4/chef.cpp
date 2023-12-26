#include"chef.h"
#include<iostream>
#include<string>
using namespace std; 
Chef::Chef(std::string _name,std::string _signatureDish){
	name=_name;
	signatureDish=_signatureDish;
} 
 


bool Chef::isSignatureDish(std::string dish){
	if(dish==signatureDish){
		return true;
	}else{
		return false;
	}
}
void Chef::cook(std::string dish){
	if(isSignatureDish(dish)==true){
		std::cout<<name<<" made an awesome "<<dish<<std::endl;
	}else{
		std::cout<<name<<" made a plain "<<dish<<std::endl;
	}
}

