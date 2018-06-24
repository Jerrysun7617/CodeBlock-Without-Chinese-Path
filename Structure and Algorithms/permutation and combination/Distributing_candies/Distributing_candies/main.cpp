#include <iostream>

using namespace std;
/*
n颗相同的糖果，分给m个人，每人至少一颗，问有多少种分法。

给定n和m，请返回方案数，保证n小于等于12，且m小于等于n。

测试样例：
10,3
返回：36
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
