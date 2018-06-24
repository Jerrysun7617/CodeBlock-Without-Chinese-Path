#include <iostream>

using namespace std;

class A{
    public:
    A(){
    }
    ~A(){
        throw 42;
    }
};

int main()
{
    try{
        int momsAge = 30;
        int sonsAge = 34;
        A a;
        if(sonsAge > momsAge){
            throw 99;
        }
    }catch (int x){
        cout<<" son can not be older than mom: "<<x<<endl;
    }

    while(1);

    return 0;
}
