#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;
/*
01背包变形。
注意到题目有一个条件，就是两队人数相差不过1,
算出最接近平均值的数的之后还要判断他否可以n / 2 或者 n / 2 + 1 个人组成。
所以计算时还要将可由几个人组成这个数的人数记录下来。
n范围100, 所以最多需要50位来记录, 要用long long来存。
综上可得转移方程 dp[w] = dp[w] | (dp[w - arr[i]] << 1);
时间复杂度

O(n*(∑x[i]))
*/




#ifndef Mothed_01

long long cha = 0;
long long one_heavy = 0;
long long two_heavy = 0;
void dfs(vector<int> &hea,int step, long long cur_heavy,long long sum,vector<bool> &visited){
    if(hea.size()%2){
        if(step == hea.size()/2 + 1){
            if((sum - cur_heavy) > cur_heavy)
            {
                if(cha >= (sum - cur_heavy) - cur_heavy){
                        one_heavy = cur_heavy;
                        two_heavy =  sum - cur_heavy;
                    cha = (sum - 2*cur_heavy);
                }
            }
            else{
                if(cha >=  cur_heavy - (sum - cur_heavy)){
                        two_heavy = cur_heavy;
                        one_heavy =  sum - cur_heavy;
                        cha = cur_heavy - (sum - cur_heavy) ;
                }
            }
            //cur_heavy = 0;
            //return;
        }
   }
   if(step == hea.size()/2 ){
            if((sum - cur_heavy) > cur_heavy)
            {
                if(cha >= (sum - cur_heavy) - cur_heavy){
                        one_heavy = cur_heavy;
                        two_heavy =  sum - cur_heavy;
                    cha = (sum - 2*cur_heavy);
                }
            }
            else{
                if(cha >=  cur_heavy - (sum - cur_heavy)){
                        two_heavy = cur_heavy;
                        one_heavy =  sum - cur_heavy;
                        cha = cur_heavy - (sum - cur_heavy) ;
                }
            }
            cur_heavy = 0;
            return;
    }
    for(int i =  0; i < hea.size() ; i++){
        if(visited[i] == false)
        {
            visited[i] = true;
            cur_heavy += hea[i];
            dfs(hea,step+1,cur_heavy,sum,visited);
            cur_heavy -= hea[i];
            visited[i] = false;
        }
    }
    return ;
}
void snack_sum(vector<int> hea, int num,long long sum){

    vector<bool> visited(num,false);

    //cout<<hea.size()<<" "<<num<<endl;
    cha = sum;
    one_heavy = 0;
    two_heavy = 0;
    dfs(hea,0,0,sum,visited);
    cout<<one_heavy<<" "<<two_heavy<<endl;
}
int get_rand(int min, int max){
    return (rand() % (max-min + 1))+ min;
}
#endif // Mothed_01

typedef long long LL;
LL dp[50005];
int a[105];

bool judge(LL x, LL n) {
    if(n % 2 == 0){
        int num = n / 2;
        return (x & (1LL << num)) != 0;
    } else {
        int num = n / 2;
        return (x & (1LL << num)) != 0 || (x & (1LL << (num + 1))) != 0;
    }
}

int main() {
    int num_count = 100;
    int n;
   while(--num_count){
        LL sum = 0;
        memset(dp, 0, sizeof(dp));
        n = get_rand(1,5);
        vector<int> hea;
        for(int i = 0; i < n; i++){
            a[i] = get_rand(1,100);
            sum += a[i];
            hea.push_back(a[i]);
            cout<<a[i]<<endl;
        }
        dp[0] = 1;
        for(int i = 0; i < n; i++){
            for(LL j = sum / 2; j >= a[i]; j--){
                    cout<< dp[j]<<" " <<  a[i]<<endl;
                dp[j] = dp[j]|(dp[j - a[i]] << 1);
                    cout<< dp[j]<<" " <<  a[i]<<endl;
            }
        }
        LL i = sum / 2;
        for(; i >= 0; i--){
            if(judge(dp[i], n)){
                printf("%lld %lld\n", i, sum - i);
                break;
            }
        }

        snack_sum(hea,n,sum);

        if(one_heavy != i ||  sum - i != two_heavy)
            break;
   }
    if(num_count)
        cout<<"this is wrong"<<endl;
    else
        cout<<"this is right"<<endl;
        while(1);
    return 0;
}
