#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
平方串 问题
*/
int divide_dynamic(string str, int size1){
        if(size1 >= str.size())
            return 0;

        vector<int> fir(str.size()- size1,0);  //
        vector<vector<int>> dp;
        int i,j;
        for( i = 0; i < size1; i++ ){
            dp.push_back(fir);
        }

        int size2 = str.size();
        bool mark = false;
        for(i = 0; i < size1; i++){
            if(str[i] == str[size1])
                mark = true;
            if(mark)
                dp[i][0]  = 1;
            else
                dp[i][0] = 0;
        }
        mark = false;
        for(j = 0; j < size2 - size1;j++){
            if(str[0] == str[size1+j])
                mark = true;
            if(mark)
                dp[0][j]  = 1;
            else
                dp[0][j] = 0;
        }


        for( i = 1 ; i < size1;i++){
            for( j = 1; j<size2 - size1;j++){
                if(str[j+size1] == str[i]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        /*
        if(dp[i-1][j-1] == 11){
            cout<<str[size1]<<" "<<str[0]<<endl;
            for(int i = 0; i < size1 ; i++){
                for(int j = 0; j < size2 - size1 ; j++){
                    cout<<dp[i][j]<<" ";
            }
                cout<<endl;
            }
              while(1);

        }
        */
        return dp[i-1][j-1];
}


int main()
{
    string str;
    while(cin>>str){
        int big  = 0, cur = 0;
        for(int i = 1; i < str.size()-1;i++){ //str.size() -1
             cur = divide_dynamic(str,i);
            // cout<<cur<<endl;
            if(big < cur){
                big = cur;
            }
        }
        cout<<big*2<<endl;
    }


    return 0;
}
