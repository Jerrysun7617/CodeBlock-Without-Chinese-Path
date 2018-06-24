//ע�⣺��������һ��char team���������������ģ����Ǽ������еĶ�Ա��ʼ��ʱ����B�ӵģ���ô��ִ�� 0-1 ������ѡ��A��ѡ��Ա�������У��������Ҫ��ģ����޸� team = 'A'����ô�ͽ����˱�ǡ�


//�������������Ĵ��룺


//[cpp] view plain copy
#include <iostream>
#include <stack>
using namespace std;

//����һ���κӶ�Ա�Ľṹ��
typedef struct people
{
    int number; //��Ա��ţ���1��ʼ
    int weight; //��Ա����
    char team; //��Ա���ڶӣ�A�ӻ���B��
} peoples;

//��ά�����ڼ�¼
//�������±��ʾ�˵ı��
//���±��ʾ����������Ҳ����ÿһ�ӵ��������ٶ����ᳬ��5000.
const int N = 100;
const int W = 5000;
int arr[N+1][W+1];

int getMax(int a,int b)
{
    return a>=b?a:b;
}

int main()
{
    cout<<"����������";
    int num;
    cin>>num;

    peoples *players = new peoples [num+1]; //����num����Ա����Ա��Ŵ�1��ʼ

    int sum = 0; //���������˵�������
    cout<<"����ÿһ���˵�������";
    //����ÿһ���˵�����
    for(int i=1; i<=num; i++)
    {
        int w = 0;
        cin>>w;
        players[i].number = i;//��Ա���
        players[i].weight = w; //��Ա������
        players[i].team = 'B'; //���趼��B�ӵĶ�Ա
        sum+=w;
    }
    int average = sum/2;

    //��ʼ����ά���еĵ�һ��
    for(int k=0; k<=W; k++) arr[0][k] = 0;
    //��ʼ����ά���еĵ�һ��
    for(int k=0; k<=N; k++) arr[k][0] = 0;

    //���н������
    for(int i=1; i<=num; i++) //�˵ı�Ŵ� 1~N
    {
        for(int j=1; j<=average; j++) //ÿһ�������� 1~average
        {
            arr[i][j] = arr[i-1][j];
            if(players[i].weight <= j)
            {
                arr[i][j] = getMax(arr[i][j],arr[i-1][j-players[i].weight]+players[i].weight);
            }
        }
    }

    cout<<"����֮���������Ϊ�� "<<sum - 2*arr[num][average]<<endl;

    //�����ǰ�õ��Ķ�ά��
    for(int i=0; i<=num; i++) //��Ʒ��Ŵ� 1~N
    {
        for(int j=0; j<=average; j++) //���������� 1~W
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }

    int remainspace = average;
    //ѡ��A�ӵĶ�Ա
    for(int i=num; i>=1; i--)
    {
        if (remainspace >= players[i].weight)
        {
            if ((arr[i][remainspace]-arr[i-1][remainspace-players[i].weight])==players[i].weight)
            {
                players[i].team = 'A'; //ѡ����A���еĶ�Ա
                remainspace = remainspace - players[i].weight;
            }
        }
    }
    stack<peoples> playerA; //��������A
    stack<peoples> playerB; //��������B

    //ͳ��A�Ӻ�B�ӵĶ�Ա
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

    //���A�ӳ�Ա
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

    //���B�ӳ�Ա
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
