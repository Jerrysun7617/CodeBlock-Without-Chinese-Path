#include <iostream>

using namespace std;
int fun(int x)
{
    int countx = 0;
    while (x)
    {
         printf("%x\n",x);
        countx++;
        x = x & (x - 1);

    }
    return countx;
}
int main()
{
    int k = 16;
    k >>= 1;
    cout << fun(500)<< endl;

    while(1);
    return 0;
}
