#include <iostream>

using namespace std;
//[cpp] view plain copy
template <class T>
inline T square(T& value)
{
    return value*value;
}

//[cpp] view plain copy
inline int max(int a, int b)
{
 return a > b ? a : b;
}
int main()
{

    cout << max(100,101) << endl;
    int st = 12;
     cout << square(st) << endl;

    system("pause");
    return 0;
}
