#include <iostream>
#include <vector>
using namespace std;
/*
n����վ�ӣ����ǵı�����δ�1��n��Ҫ����Ϊa���˱����ڱ��Ϊb���˵���ߣ�����Ҫ��һ�����ڣ����ʹ��ж������ŷ����ڶ������Ҫ��a������b����ߣ�����һ��Ҫ���ڣ�����һ���ж������ŷ���

��������n�������˵ı��a��b���뷵��һ������Ԫ�ص����飬��������Ԫ������Ϊ��������Ĵ𰸡���֤����С�ڵ���10��

����������
7,1,2
���أ�[2520,720]

*/
long long fun(int n){
    //long long st = 0;
    if(n == 1)
        return 1;
    else
        return n*fun(n-1);
}
vector<int> getWays(int n, int a, int b) {
    // write code here
    vector<int> vec;
    vec.push_back(fun(n)/2);
    vec.push_back(fun(n-1));

    return vec;
}
int main()
{
    int n  = 0;
    while(cin>>n){
        vector<int> ts = getWays(n,0,0);
        cout<<ts[0]<<" "<<ts[1]<<endl;
    }
    return 0;
}
