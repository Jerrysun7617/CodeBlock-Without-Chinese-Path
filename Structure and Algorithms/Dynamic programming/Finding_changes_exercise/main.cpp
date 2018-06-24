#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//#define Violent_methods
/*  ����Ǯ��ϰ��
������penny��penny�����е�ֵ��Ϊ�����Ҳ��ظ���ÿ��ֵ����һ����ֵ�Ļ��ң�ÿ����ֵ�Ļ��ҿ���ʹ�������ţ��ٸ���һ������aim(С�ڵ���1000)����Ҫ�ҵ�Ǯ������Ǯ�ж����ַ�����

��������penny�����Ĵ�С(С�ڵ���50)��ͬʱ����һ������aim���뷵���ж����ַ������Դճ�aim��

����������
[1,2,4],3,3
���أ�2
*/
// ����������
#ifdef Violent_methods
    int foo(const vector<int>& arr, int index, int aim)
    {
        if(aim == 0) return 1;
        else if(index >= arr.size()){
                index = 0;
                return 0; //final conditions
        }
        int strat = 0;
        for(int i = 0; arr[index]*i <= aim;i++){
            //cout<<"ret:"<<strat<<", i:"<<i<<", arr["<<index<<"]:"<< arr[index]<<", aim: "<<aim<<endl;
            strat += foo(arr,index+1, aim-arr[index]*i); //only return 1 , then plus
        }
        return strat;
    }

    int countWays(vector<int> penny, int n, int aim) {
        if(n == 0 || aim == 0)return 0;
         return foo(penny,0,aim);
    }
#endif // Violent_methods

#ifdef Remberingg_searching
    int foo(const vector<int>& arr, int index, int aim, unordered_map<string, int>& mp)
    {
        if (aim == 0)   return 1;
        if (index == arr.size())    return 0;   // ��ʱ aim != 0
        string s = to_string(index) + " " + to_string(aim);
        cout<<"s: "<<s<<endl;
        if (mp.find(s) != mp.end())  return mp[s];
        else
        {
            int ret = 0;
            for (int i = 0; arr[index] * i <= aim; i++)
            {
                cout<<"ret:"<<ret<<", i:"<<i<<", arr["<<index<<"]:"<< arr[index]<<", aim: "<<aim<<endl;

                ret += foo(arr, index + 1, aim - arr[index] * i, mp);
            }
            cout<<"map: "<<ret<<"  "<<s<<endl;
            mp[s] = ret;
            return ret;
        }
    }

    int countWays(vector<int> penny, int n, int aim) {
        if (n == 0 || aim == 0) return 0;
        unordered_map <string, int> mp;
        return foo(penny, 0, aim, mp);
    }
#endif // Remberingg_searching

    int countWays(vector<int> penny, int n, int aim) {
       // write code here
        vector<vector<int>> dp(n,vector<int>(aim+1,0));
        for(int i=0;i<n;++i){
            dp[i][0] = 1;
        }
        for(int i=0;i <= aim;++i){
            if(i % penny[0] == 0)
                dp[0][i]=1;
        }
        for(int i=1;i<n;++i){
           for (int j = 1; j < aim + 1; ++j)
           {

                if(j - penny[i]>=0)
                 {
                    dp[i][j] = dp[i][j - penny[i]] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
                cout<<"dp["<<i<<"]["<<j<<"]:"<<dp[i][j]<<", penny["<<i<<"]��"<<penny[i]<<endl;
            }
        }
        return dp[n-1][aim];
    }
int main()
{
    cout << "Hello world!" << endl;
    int num = 0;
    int aim = 0;
/*
    ����������
    [1,2,4],3,3
    ���أ�2
*/
    vector<int> arr;
    while(cin>>num>>aim){
            int input = 0;
        for(int i = 0; i < num;i++){
            cin>>input;
            arr.push_back(input);
        }
        cout<<countWays(arr,num,aim)<<endl;
    }
    return 0;
}
