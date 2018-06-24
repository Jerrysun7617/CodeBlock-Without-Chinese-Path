#include <iostream>
#include <vector>
using namespace std;

long long px = 0;
int last = 0;
int num[5];
/*

*/
long long RollBack(int k,int x,int y,vector<bool> visited,int last){
    if(k==y){
        px++;

        for(int i = 0; i < y;i++)
            cout<<num[i]<<" ";
        cout<<endl;
        return px;
        }
    else{
        for(int i=last;i<x;i++){
                num[k] = i;
                visited[i] = true;
                //********************* last = i + 1
                    RollBack(k+1,x,y,visited,i+1); // 最关键的一步就是 last = i +1;
                visited[i]=false;
            }
        }

    return px;
}

long long pos(int K,int X,int A,int Y,int B){
    long long pos = 0;

    for(int i =0; i <= X; i++)
    for(int j = 0;j <= Y; j++){
        if(A*i+B*j == K)
        {
            long long ax = 0;
            long long ay = 0;
            last = 0;
            if(i == X || i ==0)
                ax = 1;
            else{
                vector<bool> visited01(i,false);
                px = 0;
                ax =RollBack(0,X,i,visited01,last);
                ///for(int pi = 0;pi <=X;pi++)
            }
            if(j == Y || j ==0)
                ay = 1;
            else{
                vector<bool> visited02(j,false);
                px = 0;
                ay =RollBack(0,Y,j,visited02,last);
                ///for(int pi = 0;pi <=X;pi++)
            }

            pos += (ax*ay)%1000000007;
        }
    }
    return pos;
}
int main()
{
    int  K = 0;
    while(cin>>K){
         int A,X,B,Y;
        cin>>A>>X>>B>>Y;
        cout<<pos(K,X,A,Y,B)<<endl;
    }
    return 0;
}
