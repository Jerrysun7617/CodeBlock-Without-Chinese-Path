#include <iostream>
#include "Mother.h"
using namespace std;
Mother::Mother(){
     cout<<" mother constructor. "<<endl;
}

Mother::~Mother(){
    cout<<" mother deconstructor.  " <<endl;
}

void Mother::sayName(void){
    cout<< "I am mother " <<endl;
}
