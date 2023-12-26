#pragma once
#include"chef.h" 
#include<string>
#include<vector>
using namespace std;
class Manager{
public:
	vector<Chef> team;
	void newChef(Chef c);
	void order(std::string dish);
	void order(std::string dish,int chefId);
}; 
 
