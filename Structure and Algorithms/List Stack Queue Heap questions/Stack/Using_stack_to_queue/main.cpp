#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/*
    stack 的基础操作
    stack 模板类的定义在<stack>头文件中。
    stack 模板类需要两个模板参数，一个是元素类型，一个容器类型，但只有元素类型是必要
    的，在不指定容器类型时，默认的容器类型为deque。
    定义stack 对象的示例代码如下：
    stack<int> s1;
    stack<string> s2;
    stack 的基本操作有：
    入栈，如例：s.push(x);
    出栈，如例：s.pop();注意，出栈操作只是删除栈顶元素，并不返回该元素。
    访问栈顶，如例：s.top()
    判断栈空，如例：s.empty()，当栈空时，返回true。
    访问栈中的元素个数，如例：s.size()

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
