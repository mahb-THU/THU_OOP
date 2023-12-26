#include"car.h"
Car::Car(int _num,string _name):Vehicle(_num,_name,"car") { }
void Car::describe(){
    cout<<"A car with "<<w.get_num()<<" wheels and a "<<e.get_name()<<" engine."<<endl;
}
