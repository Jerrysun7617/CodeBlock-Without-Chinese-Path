#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#define LL long long
using namespace std;
char s[]="0123456789";
int vis[15];
char ans[10];
void dfs(int x,int d,int k,int last)
{
    if(d==k)
    {
        for(int i=0;i<k;i++) cout<<ans[i];cout<<endl;
        return ;
    }
    int f=-1;
    for(int i=last;i<x;i++)
    {
        //if(vis[i]==0)
        {
            //if(f==-1|| f!=s[i])
            {
                f=s[i];
                vis[i]=1;
                ans[d]=s[i];
                dfs(x,d+1,k,i+1);
                vis[i]=0;
            }
        }
    }
}
int main()
{

    int x,n;
    while(cin>>x>>n)
        dfs(x,0,n,0);
    while(1);
    return 0;
}
