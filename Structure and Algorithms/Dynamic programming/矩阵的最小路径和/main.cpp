#include <iostream>

using namespace std;

int min_path(int matrix[100][100], int M, int N){
    int minvalue = 0;
    /*
    for(int i = 0; i < N;i++){
        for(int j = 0;j< M;j++)
            cout<<matrix[i][j]<<endl;
        cout<<endl;
    }
    */
    int dp[100][100];
    dp[0][0] = matrix[0][0];
    for(int i = 1;i < M;i++)
        dp[0][i] = dp[0][i-1] + matrix[0][i];
    for(int j = 1;j<N;j++)
        dp[j][0] = dp[j-1][0] + matrix[j][0];

    for(int i = 1; i < M; i++)
        for(int j = 1;j< N ;j++){
            dp[j][i] = min(dp[j-1][i],dp[j][i-1]) + matrix[j][i];  // key point
    }
    for(int i = 0; i < N;i++){
        for(int j = 0;j< M;j++)
                cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[N-1][M-1];
}
int main()
{
    while(1){
        int M,N;
        cin>>M>>N; // M == row N == Col
        int matrix[100][100];
        for(int i = 0; i < N;i++)
            for(int j = 0;j< M;j++)
                cin>>matrix[i][j];

        cout<<"The min path:"<<min_path(matrix,M,N)<<endl;
    }
    return 0;
}
