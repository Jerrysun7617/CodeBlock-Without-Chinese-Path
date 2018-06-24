#include <iostream>

using namespace std;
int ans[100];
void dfs(int d,int sum,int pre)
{
    if(sum==0)
    {
        for(int i=0;i<d-1;i++) cout<<ans[i]<<"+";cout<<ans[d-1]<<endl;
        return ;
    }
   for(int i=sum;i>0;i--)
   {
        cout<<"d: "<<d<<", i: "<<i<<", sum: "<<sum<<endl;

        ans[d]=i;
        //if(i <= pre)
            dfs(d+1,sum-i,i);
        //ans[d] = 0;
   }
}
int main()
{
    cout << "Hello world!" << endl;
    int d,m;
    while(cin>>d>>m){
        dfs(d,m,m);
    }
    return 0;
}
