//注意：这里设置一个char team；的作用是这样的，我们假设所有的队员初始的时候都是B队的，那么在执行 0-1 背包的选择（A队选队员）过程中，如果符合要求的，就修改 team = 'A'，那么就进行了标记。


//下面贴出完整的代码：


//[cpp] view plain copy
#include <iostream>
#include <stack>
using namespace std;

//定义一个拔河队员的结构体
typedef struct people
{
    int number; //队员编号，从1开始
    int weight; //队员重量
    char team; //队员所在队：A队或者B队
} peoples;

//二维表用于记录
//其中行下标表示人的编号
//列下标表示背包质量，也就是每一队的质量，假定不会超过5000.
const int N = 100;
const int W = 5000;
int arr[N+1][W+1];

int getMax(int a,int b)
{
    return a>=b?a:b;
}

int main()
{
    cout<<"输入人数：";
    int num;
    cin>>num;

    peoples *players = new peoples [num+1]; //创建num名队员，队员编号从1开始

    int sum = 0; //计算所有人的总质量
    cout<<"输入每一个人的质量：";
    //输入每一个人的质量
    for(int i=1; i<=num; i++)
    {
        int w = 0;
        cin>>w;
        players[i].number = i;//队员编号
        players[i].weight = w; //队员的重量
        players[i].team = 'B'; //假设都是B队的队员
        sum+=w;
    }
    int average = sum/2;

    //初始化二维表中的第一行
    for(int k=0; k<=W; k++) arr[0][k] = 0;
    //初始化二维表中的第一列
    for(int k=0; k<=N; k++) arr[k][0] = 0;

    //逐行进行填表
    for(int i=1; i<=num; i++) //人的编号从 1~N
    {
        for(int j=1; j<=average; j++) //每一队质量从 1~average
        {
            arr[i][j] = arr[i-1][j];
            if(players[i].weight <= j)
            {
                arr[i][j] = getMax(arr[i][j],arr[i-1][j-players[i].weight]+players[i].weight);
            }
        }
    }

    cout<<"两队之间的质量差为： "<<sum - 2*arr[num][average]<<endl;

    //输出当前用到的二维表
    for(int i=0; i<=num; i++) //物品编号从 1~N
    {
        for(int j=0; j<=average; j++) //背包容量从 1~W
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }

    int remainspace = average;
    //选出A队的队员
    for(int i=num; i>=1; i--)
    {
        if (remainspace >= players[i].weight)
        {
            if ((arr[i][remainspace]-arr[i-1][remainspace-players[i].weight])==players[i].weight)
            {
                players[i].team = 'A'; //选出是A队中的队员
                remainspace = remainspace - players[i].weight;
            }
        }
    }
    stack<peoples> playerA; //创建队伍A
    stack<peoples> playerB; //创建队伍B

    //统计A队和B队的队员
    for(int i = 1; i<= num; i++)
    {
        if(players[i].team == 'A')
        {
            playerA.push(players[i]);
        }
        else
        {
            playerB.push(players[i]);
        }
    }

    //输出A队成员
    cout<<"A:"<<endl;
    int sumA = 0;
    while(!playerA.empty())
    {
        cout<<"Number:"<<playerA.top().number<<"   Weight:"<<playerA.top().weight<<endl;
        sumA+=playerA.top().weight;
        playerA.pop();
    }
    cout<<"A team sum of weight = "<<sumA<<endl;

    cout<<endl;

    //输出B队成员
    cout<<"B:"<<endl;
    int sumB = 0;
    while(!playerB.empty())
    {
        cout<<"Number:"<<playerB.top().number<<"   Weight:"<<playerB.top().weight<<endl;
        sumB+=playerB.top().weight;
        playerB.pop();
    }
    cout<<"B team sum of weight = "<<sumB<<endl;

    delete [] players;

    while(1);
    return 0;
}
