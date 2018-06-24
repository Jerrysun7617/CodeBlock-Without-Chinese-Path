#include <iostream>

using namespace std;
/*
A(A也是他的编号)是一个孤傲的人，在一个n个人(其中编号依次为1到n)的队列中，他于其中的标号为b和标号c的人都有矛盾，所以他不会和他们站在相邻的位置。现在问你满足A的要求的对列有多少种？

给定人数n和三个人的标号A,b和c，请返回所求答案，保证人数小于等于11且大于等于3。

测试样例：
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
