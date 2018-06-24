#include <iostream>

using namespace std;

int findMinCost(string A, int n, string B, int m, int c0, int c1, int c2) {
    // write code here
    /*
    while(m>n){
        A.push_back(' ');
        n++;
    }*/

    int dp[n+1][m+1]={0}; //代价总值
    dp[0][0] = 0;
    //c0插入 c1删除 c2修改
    cout<<n<<"   "<<m<<endl;
    for(int i = 1;i<= m;i++)
        dp[0][i] = i*c0;
    for(int i = 1 ; i <= n;i++)
        dp[i][0] = i*c1;
    /*
    for(int i =0; i <= n;i++){
        for(int j =0;j<= m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    */

    for(int i =1; i <= n;i++)
        for(int j =1;j<=m;j++){
        //dp[i][j]
                   // possible cose
           int p1 = c1 + dp[i-1][j];
           int p2 = c0 + dp[i][j-1];
        int minlen = min(p1,p2);
        if(A[i-1] == B[j-1]){
            minlen = min(dp[i-1][j-1],minlen);
        }
        else
            minlen = min(dp[i-1][j-1]+c2,minlen);
           dp[i][j] = minlen;
    }
    /*
     cout<<"   ";
    for(int j =1;j<=m;j++)
        cout<<B[j-1]<<" ";
        cout<<endl;
    for(int i =0; i <= n;i++){
        if(i != 0)
            cout<<A[i-1]<<" ";
        else
            cout<<"  ";
        for(int j =0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    return dp[n][m];
}

int main()
{
    cout << "Hello world!" << endl;
    string A= "bbca";
    string B= "cabacab";

    cout<<findMinCost(A,A.size(),B,B.size(),1,2,7)<<endl;

    while(1);
    return 0;
}
