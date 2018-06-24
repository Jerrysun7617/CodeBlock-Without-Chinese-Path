#include <iostream>
#include <vector>
#include <algorithm>
/*
一个背包有一定的承重cap，有N件物品，每件都有自己的价值，记录在数组v中，也都有自己的重量，记录在数组w中，每件物品只能选择要装入背包还是不装入背包，要求在不超过背包承重的前提下，选出物品的总价值最大。

给定物品的重量w价值v及物品数n和承重cap。请返回最大总价值。

测试样例：
[1,2,3],[1,2,3],3,6
返回：
*/
using namespace std;
int maxValue(vector<int> w, vector<int> v, int n, int cap) {
    // write code here
    //first two
    int dp[200][2000];

    //现在把重量分开
    for(int j = 0;  j <=cap ; j++){
        dp[0][j] = (j>=w[0])? v[0]:0;
    }

    //row is N的背包
    // 列数为W背包重量
   for(int i = 1; i < n ;i++)
        for(int j = 0;j <= cap;j++){
        //选不选这个
        if(j >= w[i-1]){ // 当找到一个适合的重量
                   // write code here
            //dp[i][j]前i件物品（i不一定装进去）总重不超过j的最大价值
            //两种情况：dp[i][j]=dp[i-1][j]，即第i件物品不放入
            //        dp[i][j]=dp[i-1][j-w[i]]+v[i]，即第i件物品放入,取两者较大
            dp[i][j]  = max(dp[i-1][j],(dp[i-1][j-w[i-1]]+v[i-1]));
        }
        else
            dp[i][j] = dp[i-1][j];
   }

     for(int i = 0; i < n ;i++){
        for(int j = 0;j <= cap;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
     }

   return dp[n-1][cap];
}
int main()
{
    cout << "Hello world!" << endl;
    /*
    int n =5, cap = 90;
    int a1[5] = {17,34,38,42,36};
    vector<int> w(a1,a1+5);
    int v1[5] = {335,406,160,452,311};
    vector<int> v(v1,v1+5);
    */
    int n =3, cap = 6;
    int a1[3] = {1,2,3};
    vector<int> w(a1,a1+3);
    int v1[3] = {1,2,3};
    vector<int> v(v1,v1+3);

    cout<<maxValue(w,v,n,cap)<<endl;

    while(1);
    return 0;
}
