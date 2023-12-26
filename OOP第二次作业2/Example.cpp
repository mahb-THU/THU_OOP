#include <iostream>
#include "Example.h"

using namespace std;
int Example::count=0;	// (2)

Example::Example(int data) {
	count++;                                      // (3)
	classdata=data;                               // (3)
	index=count;                                  // (3)
	cout<<"Example #"<<index<<" is created"<<endl;// (3)
}

void Example::getData() {
	cout<<"The data of Example #"<<index<<" is "<<classdata<<endl;// (4)
}

Example::~Example() {
	cout<<"Example #"<<index<<" is destroyed"<<endl;// (5)
}