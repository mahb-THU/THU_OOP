#include <iostream>
#include "Example.h"

using namespace std;

void create_example(int n) {
	
	cout << "--------create_example is ready--------\n";
	
	Example* e[10];
	
	for (int i = 0; i < n; i++)
		e[i] = new Example(i);
	static Example d(2333);// (6)
    for(int i=0;i<n;i++){  // (6)
		e[i]->getData();   // (6)
	}                      // (6)
	for(int i=0;i<n;i++){  // (6)
		e[i]->~Example();  // (6)
	}                      // (6)
	d.getData();           // (6)
	cout << "--------create_example is over--------\n";
}
Example a(23);// (7)

int main() {

	cout << "--------main_function is ready--------\n";

	Example b(233);// (8)
		
	create_example(3);
	
	Example c(23333);// (9)
    a.getData();     // (9)
	b.getData();     // (9)
	c.getData();     // (9)
	cout << "--------main_function is over---------\n";

	return 0;
}
