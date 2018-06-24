#include <iostream>
#include "Daughter.h"
#include "Mother.h"
using namespace std;

class mather{
private:
    string name;
    int num;

public:
    mather(){}
    mather(string na, int nu):name(na),num(nu){cout<<na<<" "<<nu<<endl;}
    virtual void print() = 0;
};
class child: public mather{

public:
    child(string na, int nu):mather(){

        //mather(na,nu);
    }
    void print(){
        cout<<"here"<<endl;
    }
};
int main()
{
   //Mother mum;
    //mum.sayName();

    Daughter Dau;
    //Dau.sayName();
    Dau.doSomething();
    //while(1);

    child * ch = new child("HELLO",2);
    ch->print();


    getchar();
    return 0;
}

