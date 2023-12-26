#include"manager.h"
#include"chef.h"
#include<iostream>
#include<string> 

void Manager::newChef(Chef A){
	team.push_back(A);
}
void Manager::order(std::string dish){
	int count=0;
	for(int i=0;i<team.size();i++){
		if(team[i].isSignatureDish(dish)==true){
			team[i].cook(dish);
			break;
		}
		count++;
	} 
	if(count==team.size()){
		team[0].cook(dish);
	}
}
void Manager::order(std::string dish,int chefId){
	team[chefId].cook(dish);
}
