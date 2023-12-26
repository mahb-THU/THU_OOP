#ifndef __EXAMPLE__
#define __EXAMPLE__
	
class Example {
		
private:
	
	int classdata,index;   // (1)
	static int count;// (1)
			
public:
	
	Example(int data);
	void getData();
	~Example();

};
		
#endif