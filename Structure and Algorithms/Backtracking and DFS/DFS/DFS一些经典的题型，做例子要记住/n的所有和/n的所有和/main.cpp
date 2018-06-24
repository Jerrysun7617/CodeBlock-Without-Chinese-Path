#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#define LL long long
using namespace std;
int ans[10];
void dfs(int d,int sum,int pre)
{
    if(sum==0)
    {
        for(int i=0;i<d-1;i++) cout<<ans[i]<<"+";cout<<ans[d-1]<<endl;
        return ;
    }
   for(int i=sum;i>0;i--)
   {
        ans[d]=i;
        if(i<=pre) dfs(d+1,sum-i,i);
   }
}
using namespace std;
int main()
{
   int n;
   while(cin>>n)
    dfs(0,n,n);
    return 0;
}
