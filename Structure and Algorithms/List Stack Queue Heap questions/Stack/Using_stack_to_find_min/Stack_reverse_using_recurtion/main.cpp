#include <iostream>
#include <vector>
using namespace std;

int get_last(vector<int> &A){
    int result = A.back();
    A.pop_back();
    if(A.empty())
        return result;
    else{
        int last = get_last(A);
        A.push_back(result);
        return last;
    }
}

vector<int> reverseStack(vector<int> &A, int n) {
    // write code here
    if(A.empty())
        return A;

    int last = get_last(A);
    cout<<last<<endl;
    //A.pop
    //A.pop_back();
    reverseStack(A,A.size());
     cout<<last<<endl;
    A.push_back(last);

    return A;
}

int main()
{
    cout << "Hello world!" << endl;
    int arr[4] = {1,2,3,4};
    vector<int> ts(arr,arr+4);
    vector<int> st= reverseStack(ts, ts.size());

    for(int i = 0; i < st.size();i++)
        cout<<st[i]<<" ";
    while(1);
    return 0;
}
