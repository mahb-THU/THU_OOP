#include "Calculator.h"
#include"LevelStrategy.h"
#include"PerformStrategy.h"
using namespace std;
Calculator::Calculator(LevelStrategy* m_levelStrategy,PerformStrategy* m_perfomStrategy){
    l=m_levelStrategy->getlevel();
    g=m_perfomStrategy->getgrade();
    p=m_perfomStrategy->getperform();
}
int Calculator::get_base(){
    switch(l){
        case 1:
        return 2000;
        break;
        case 2:
        return 5000;
        break;
        case 3:
        return 10000;
        break;
        default:
        break;
    }
}
int Calculator::get_total(int base){
    switch(g){
        case 1:
        return base+1000;
        break;
        case 2:
        return base+p*base;
        break;
        case 3:
        return base+2*p*base;
        break;
        default:
        break;
    }
}

