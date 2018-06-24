#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#define LL long long
using namespace std;
char s[]="gggrryyyyy";
int vis[15];
char ans[10];
void dfs(int d,int last)
{
    if(d==8)
    {
        for(int i=0;i<8;i++) cout<<ans[i];cout<<endl;
        return ;
    }
    int f=-1;
    for(int i=last;i<10;i++)
    {
        if(vis[i]==0)
        {
            if(f==-1|| f!=s[i])
            {
                f=s[i];
                vis[i]=1;
                ans[d]=s[i];
                dfs(d+1,i+1);
                vis[i]=0;
            }
        }
    }
}
using namespace std;
int main()
{

    dfs(0,0);

    while(1);
    return 0;
}
