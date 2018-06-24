#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/*
    stack �Ļ�������
    stack ģ����Ķ�����<stack>ͷ�ļ��С�
    stack ģ������Ҫ����ģ�������һ����Ԫ�����ͣ�һ���������ͣ���ֻ��Ԫ�������Ǳ�Ҫ
    �ģ��ڲ�ָ����������ʱ��Ĭ�ϵ���������Ϊdeque��
    ����stack �����ʾ���������£�
    stack<int> s1;
    stack<string> s2;
    stack �Ļ��������У�
    ��ջ��������s.push(x);
    ��ջ��������s.pop();ע�⣬��ջ����ֻ��ɾ��ջ��Ԫ�أ��������ظ�Ԫ�ء�
    ����ջ����������s.top()
    �ж�ջ�գ�������s.empty()����ջ��ʱ������true��
    ����ջ�е�Ԫ�ظ�����������s.size()

*/
vector<int> twoStack(vector<int> ope, int n) {
    // write code here
    stack<int> st1;
    vector<int> po;

    for(int i = 0; i < n;i++)
    {
        if(ope[i] > 0) // ope
        {
            st1.push((int)ope[i]);
        }
        else{
            stack<int>  st2;
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            if(!st2.empty()){
                po.push_back(st2.top());
                st2.pop();
            }
            while(!st2.empty()){
                st1.push(st2.top());
                st2.pop();
            }
        }
    }

    return po;
}
int main()
{
    cout << "Hello world!" << endl;
    int arr[6] ={1,2,3,0,4,0};
    vector<int> st(arr,arr+6);
    vector<int> vec = twoStack(st,6);

    for(int  i =0 ; i < vec.size(); i++)
        cout<<vec[i]<<" ";
    while(1);
    return 0;
}
