#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    float * num = new float[10];
    //while()
    while(1){
        int i = 0;
        for(;i<10;i++)
            cin>>num[i];
        float  minnum = num[0];
        for(i = 1;i<10;i++)
                //minnum = max(minnum,num[i]);
                minnum = min(minnum,num[i]);
        cout<<minnum<<endl;
    }
    return 0;
}
