#include <iostream>

using namespace std;

template <class mytype>
mytype getmax(mytype x, mytype y){
    return (x>y?x:y);
}
int main()
{

    cout <<getmax<double>(1.0,3) << endl;

    while(1);
    return 0;
}
