#pragma once
#include<string>
#include<iostream>
#include"Cow.h"
class Farm{
	public:
		Cow cows[105];
		int cownumber=0;
		int count=0;
		int add[105]={0};
		int mealstart[105]={0};
		float product[105];
		float sum=0;
		Farm(int n){
			cownumber=n;
		}
		void addCow(Cow cow){
	        cows[count]=cow;
			count++;
		}
		void supply(std::string name,int a){
			for(int j=0;j<cownumber;j++){
				if(name==cows[j].name){
					add[j]+=a;
				}
			}
		}
		void startMeal(){
			for(int j=0;j<cownumber;j++){
				mealstart[j]+=add[j];
				add[j]=0;
			}
		}
		void produceMilk(){
			for(int j=0;j<cownumber;j++){
				product[j]=0;
			}
			for(int j=0;j<cownumber;j++){
				if(mealstart[j]<cows[j].lowlimit&&mealstart[j]>0){
				    product[j]=cows[j].milk/2.0;
			    }
			    if(mealstart[j]==0){
			    	product[j]=0;
				}
				if(mealstart[j]>=cows[j].lowlimit){
					product[j]=cows[j].milk;
				}
				sum+=product[j];
			}
			for(int j=0;j<cownumber;j++){
				if(mealstart[j]<=cows[j].highlimit){
					mealstart[j]=0;
				}else{
					mealstart[j]=mealstart[j]-cows[j].highlimit;
				}
			}
			for(int j=0;j<cownumber;j++){
                  add[j]=0;
			}
		}
		float getMilkProduction(){
			return sum;
		}
};
