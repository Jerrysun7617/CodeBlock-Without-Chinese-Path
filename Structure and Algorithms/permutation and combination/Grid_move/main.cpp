#include <iostream>
using namespace std;
/*
在XxY的方格中，以左上角格子为起点，右下角格子为终点，每次只能向下走或者向右走，请问一共有多少种不同的走法

给定两个正整数int x,int y，请返回走法数目。保证x＋y小于等于12。

测试样例：
2,2
返回：2
*/
int countWays(int x, int y) {
    // write code here
    int total = x + y -2;
    int sum = 1 , di =1;
    for(int i = total; i > total - x +1 && i>=1;i-- )
        sum *= i;
    for(int i = 1; i <= x-1;i++)
        di *= i;
    return sum/di;
}
int main()
{
    int x,y;
    while(cin>>x>>y)
        cout<<countWays(x,y)<<endl;

    return 0;
}
