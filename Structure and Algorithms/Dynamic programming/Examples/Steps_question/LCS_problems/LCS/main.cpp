#include <iostream>
#include <vector>
using namespace std;

/*最长公共子序列*/

int findLCS(string A, int n, string B, int m) {
    // write code here
    //int * L = new int[100];
    int * p = new int(100);
    delete p;

    vector<int> fir(n,0);
    vector<vector<int>> dp;
    for(int i = 0; i < m;i++)
        dp.push_back(fir);

    bool mark = false;
    for(int i = 0;i < m;i++)
    {
        // only one in B
        if(A[0] == B[i]){
            mark  = true;
        }
        if(mark)
            dp[i][0] = 1;
    }
    mark = false;
    for(int i = 0;i < n;i++)
    {
        // only one in B
        if(A[i] == B[0]){
            mark  = true;
        }
        if(mark)
            dp[0][i] = 1;
    }

    for(int i = 1; i < m ; i++){
        for(int j = 1; j <n;j++){
            //three situations for getting dp[i][j]
            //one
           //cout<<B[i]<<" "<<A[j]<<endl;
            //cout<<dp[i-1][j]<<" "<< dp[i-1][j]<<" "<< dp[i-1][j-1] <<endl;
            if(A[j] == B[i])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] =  dp[i-1][j] > dp[i][j-1]?dp[i-1][j]:dp[i][j -1];
        }
    }
    for(int i = 0; i < m ; i++){
        for(int j = 0; j <n;j++){
                cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[m-1][n-1];
}

int main()
{
    //cout << "Hello world!" << endl;

    string A,B;
    while(cin>>A>>B){

        cout<<findLCS(A,A.size(),B,B.size())<<endl;
    }
    return 0;
}
