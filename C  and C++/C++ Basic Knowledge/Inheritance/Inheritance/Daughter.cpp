#include <iostream>
#include "Daughter.h"

using namespace std;

Daughter::Daughter(){
    cout<< "  Daughter constructor."<<endl;
}
Daughter::~Daughter(){
    cout<< "  Daughter deconstructor."<<endl;
}

void Daughter::doSomething(void){
    publicv = 1;
    protectedv = 2;
    //privatev = 3;

    cout<<publicv<<"   "<<protectedv<<endl;
}
