#include <iostream>

using namespace std;
/*
A(AҲ�����ı��)��һ���°����ˣ���һ��n����(���б������Ϊ1��n)�Ķ����У��������еı��Ϊb�ͱ��c���˶���ì�ܣ����������������վ�����ڵ�λ�á�������������A��Ҫ��Ķ����ж����֣�

��������n�������˵ı��A,b��c���뷵������𰸣���֤����С�ڵ���11�Ҵ��ڵ���3��

����������
6,1,2,3
288

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
int getWays(int n, int A, int b, int c) {
    int sum = 0;

    //thinking the first and the last poisition
    sum += (n-3)*jie(n-2) *2;
    //A is in the middle
    sum += (n-2)*CN(n-3,2)*2*jie(n-3);

    return sum;
}
int main()
{
    int n,A,b,c;
    while(cin>>n>>A>>b>>c)
        cout<<getWays(n,A,b,c)<<endl;
    return 0;
}
