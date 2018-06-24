#include <iostream>

using namespace std;

/*
假设有n对左右括号，请求出合法的排列有多少个？合法是指每一个括号都可以找到与之配对的括号，比如n=1时，()是合法的，但是)(为不合法。

给定一个整数n，请返回所求的合法排列数。保证结果在int范围内。

测试样例：
1
返回：1
*/

/*
n个数进出栈的顺序有多少种？假设栈的容量无限大。

给定一个整数n，请返回所求的进出栈顺序个数。保证结果在int范围内。

测试样例：
1
返回：1
*/
/*
2n个人排队买票，n个人拿5块钱，n个人拿10块钱，票价是5块钱1张，每个人买一张票，售票员手里没有零钱，问有多少种排队方法让售票员可以顺利卖票。

给定一个整数n，请返回所求的排队方案个数。保证结果在int范围内。

测试样例：
1
返回：1
*/

/*
12个高矮不同的人，排成两排，每排必须是从矮到高排列，而且第二排比对应的第一排的人高，问排列方式有多少种？

给定一个偶数n，请返回所求的排列方式个数。保证结果在int范围内。

测试样例：
1
返回：1
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
int countLegalWays(int n) {
    // write code here
   return CN(2*n,n)/(n+1);
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
