#include <iostream>

using namespace std;
int vis[15];
char s[]="gggrryyyyy";//�����ɫ����
char ans[10];//��ŵ�ǰ����
void dfs(int d)
{
    if(d==8)
    {
        for(int i=0;i<d;i++) printf("%c",ans[i]);
        printf("\n");
        return ;
    }
    for(int i=0;i<10;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            ans[d]=s[i];
            dfs(i);
            vis[i]=0;
        }
    }
}
int main()
{
    int n = 0;
    while(cin>>n){
        dfs(n);
    }
    return 0;
}
