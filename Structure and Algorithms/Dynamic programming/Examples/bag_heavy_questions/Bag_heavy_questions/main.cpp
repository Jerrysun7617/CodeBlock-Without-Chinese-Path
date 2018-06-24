#include <iostream>
#include <vector>
#include <algorithm>
/*
һ��������һ���ĳ���cap����N����Ʒ��ÿ�������Լ��ļ�ֵ����¼������v�У�Ҳ�����Լ�����������¼������w�У�ÿ����Ʒֻ��ѡ��Ҫװ�뱳�����ǲ�װ�뱳����Ҫ���ڲ������������ص�ǰ���£�ѡ����Ʒ���ܼ�ֵ���

������Ʒ������w��ֵv����Ʒ��n�ͳ���cap���뷵������ܼ�ֵ��

����������
[1,2,3],[1,2,3],3,6
���أ�
*/
using namespace std;
int maxValue(vector<int> w, vector<int> v, int n, int cap) {
    // write code here
    //first two
    int dp[200][2000];

    //���ڰ������ֿ�
    for(int j = 0;  j <=cap ; j++){
        dp[0][j] = (j>=w[0])? v[0]:0;
    }

    //row is N�ı���
    // ����ΪW��������
   for(int i = 1; i < n ;i++)
        for(int j = 0;j <= cap;j++){
        //ѡ��ѡ���
        if(j >= w[i-1]){ // ���ҵ�һ���ʺϵ�����
                   // write code here
            //dp[i][j]ǰi����Ʒ��i��һ��װ��ȥ�����ز�����j������ֵ
            //���������dp[i][j]=dp[i-1][j]������i����Ʒ������
            //        dp[i][j]=dp[i-1][j-w[i]]+v[i]������i����Ʒ����,ȡ���߽ϴ�
            dp[i][j]  = max(dp[i-1][j],(dp[i-1][j-w[i-1]]+v[i-1]));
        }
        else
            dp[i][j] = dp[i-1][j];
   }

     for(int i = 0; i < n ;i++){
        for(int j = 0;j <= cap;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
     }

   return dp[n-1][cap];
}
int main()
{
    cout << "Hello world!" << endl;
    /*
    int n =5, cap = 90;
    int a1[5] = {17,34,38,42,36};
    vector<int> w(a1,a1+5);
    int v1[5] = {335,406,160,452,311};
    vector<int> v(v1,v1+5);
    */
    int n =3, cap = 6;
    int a1[3] = {1,2,3};
    vector<int> w(a1,a1+3);
    int v1[3] = {1,2,3};
    vector<int> v(v1,v1+3);

    cout<<maxValue(w,v,n,cap)<<endl;

    while(1);
    return 0;
}
