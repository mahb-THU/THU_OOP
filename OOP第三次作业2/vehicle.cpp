#include"vehicle.h"
Vehicle::Vehicle(int _num,string _name, string vehicle_name):e(_name),w(_num){
    cout<<"Finish building a " << vehicle_name << " with "<<w.get_num()<<" wheels and a "<<e.get_name()<<" engine."<<endl;
}
void Vehicle::describe(){
    cout<<"A vehicle with "<<w.get_num()<<" wheels and a "<<e.get_name()<<" engine."<<endl;
}