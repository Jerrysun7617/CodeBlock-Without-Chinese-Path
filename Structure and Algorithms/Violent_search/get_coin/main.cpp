#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#define LL long long

using namespace std;
int ans=0;
int a[105]={5,2,1};
void dfs(int cur,int last)
{
    if(cur==0)
    {
        ans++;
        return ;
    }
    for(int i=last;i<3;i++)
        if(cur>=a[i]) dfs(cur-a[i],i);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    for(int i=5;i<=5;i++)
    {
        ans=0;
        dfs(i,0);
        printf("%d\n",ans);
    }

    while(1);
    return 0;
}
