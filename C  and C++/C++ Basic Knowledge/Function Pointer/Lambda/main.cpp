#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

/*   //without a parameters
void ForEach(const vector<int> &values, void(*func)(int)){
    for(int value : values)
        func(value);
}
*/
void ForEach(const vector<int> &values, const function<void(int)> &func){
    for(int value : values)
        func(value);
}
int main()
{
    vector<int> values = {1,2,3,4,5};

    int a = 5;


    //example for function pointer
    //ForEach(values, [](int value){cout<<"value: "<<value<<endl;});

    /*
     auto lambda = [](int value){cout<<"value: "<<a<<endl;};
    ForEach(values, lambda);
    */

    auto lambda = [=](int value){cout<<"value: "<<a<<endl;};
    ForEach(values, lambda);

    //system("pause");
    getchar();
    return 0;
}
