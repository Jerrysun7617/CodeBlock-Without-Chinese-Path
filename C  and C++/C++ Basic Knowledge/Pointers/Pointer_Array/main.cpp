#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int arr[6] = {0,1,2,3,4,5};
    int * test = arr;
    cout<<*++test<<endl;

    getchar();

    return 0;
}
