#include <iostream>

using namespace std;
/*
n����ͬ���ǹ����ָ�m���ˣ�ÿ������һ�ţ����ж����ַַ���

����n��m���뷵�ط���������֤nС�ڵ���12����mС�ڵ���n��

����������
10,3
���أ�36
*/
int CN(int n, int cn){
    int zishu = 1;
    int shangshu = 1;
    for(int i = n; i > n - cn; i--)
        zishu *= i;
    for(int i = 1; i<= cn; i++)
        shangshu *= i;

    return zishu/shangshu;
}
int jie(int n){
    if(n==1)
        return 1;
    else
        return n*jie(n-1);
}
int getWays(int n, int m) {
    // write code here
    return CN(n-1,m-1);
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
