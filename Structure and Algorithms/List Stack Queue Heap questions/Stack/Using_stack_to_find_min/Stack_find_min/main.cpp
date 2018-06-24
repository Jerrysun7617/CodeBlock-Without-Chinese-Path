#include <iostream>
#include <stack>
using namespace std;
    stack<int> st;
    stack<int> min;
    void push(int value) {
        st.push(value);
        if(min.empty())
            min.push(value);
        else
        {
            if(min.top()< value)
                min.push(value);
            else
                min.pop(min.top());
        }
    }
    void pop() {
        if(!st.empty()){
            st.pop();
            min.pop();
        }
    }
    int top() {
        return st.top();
    }
    int min() {
         return min.top();
    }
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
