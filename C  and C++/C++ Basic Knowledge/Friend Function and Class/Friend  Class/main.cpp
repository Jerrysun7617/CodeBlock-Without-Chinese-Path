#include <iostream>
using namespace std;
class Friendclass;
class Distance {
    private:
        int meter;
    public:
        Distance(): meter(10){ }
        //friend int func(Distance); //friend function
        friend class Friendclass;
};
class Friendclass{
    public:
        void func( Distance);
};

void Friendclass::func(class Distance ele){
    cout<<ele.meter<<endl;

};
/*
int func(Distance d){
    //function definition
    d.meter=10; //accessing private data from non-member function
    return d.meter;
}*/

int main(){
    Distance D;
    Friendclass B;
    B.func(D);
    system("pause");
    return 0;
}
