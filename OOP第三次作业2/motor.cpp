#include"motor.h"
Motor::Motor(int _num,string _name):Vehicle(_num,_name,"motor"){
}
void Motor::describe(){
    cout<<"A motor with "<<w.get_num()<<" wheels and a "<<e.get_name()<<" engine."<<endl;
}
void Motor::sell(){
    cout<<"A motor is sold!"<<endl;
}