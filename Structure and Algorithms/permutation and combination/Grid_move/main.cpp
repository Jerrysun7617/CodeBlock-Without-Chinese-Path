#include <iostream>
using namespace std;
/*
��XxY�ķ����У������ϽǸ���Ϊ��㣬���½Ǹ���Ϊ�յ㣬ÿ��ֻ�������߻��������ߣ�����һ���ж����ֲ�ͬ���߷�

��������������int x,int y���뷵���߷���Ŀ����֤x��yС�ڵ���12��

����������
2,2
���أ�2
*/
int countWays(int x, int y) {
    // write code here
    int total = x + y -2;
    int sum = 1 , di =1;
    for(int i = total; i > total - x +1 && i>=1;i-- )
        sum *= i;
    for(int i = 1; i <= x-1;i++)
        di *= i;
    return sum/di;
}
int main()
{
    int x,y;
    while(cin>>x>>y)
        cout<<countWays(x,y)<<endl;

    return 0;
}
