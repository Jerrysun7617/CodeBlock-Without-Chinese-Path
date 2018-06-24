#include<iostream>
using namespace std;
void ConstTest1(){


}
void ConstTest2(){
    int i;
    cout<<"please input a integer:";
    cin>>i;
    const int a = i;
    int &r = const_cast<int &>(a);
    r++;
    cout<<a<<endl;
}
int main(){
    ConstTest1();
    ConstTest2();

    system("pause");
    return 0;
}
