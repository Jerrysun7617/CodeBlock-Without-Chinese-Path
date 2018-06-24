#include <iostream>
using namespace std;

class Distance {
    private:
        int meter;
    public:
        Distance(): meter(0){ }
        friend int func(Distance); //friend function
};

int func(){
    //function definition
    Distance d.meter=10; //accessing private data from non-member function
    return d.meter;
}

int main(){
    Distance D;
    cout<<"Distace: "<<func(D);
    system("pause");
    return 0;
}
