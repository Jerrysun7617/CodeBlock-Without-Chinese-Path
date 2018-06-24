#include <iostream>
#include <vector>
using namespace std;

vector<int> twoStacksSort(vector<int> &numbers) {
    // write code here
    vector<int> temp;
    while(!numbers.empty())
    {

        int top = numbers.back();
        numbers.pop_back();
        while(!temp.empty() && temp.back() < top){
            numbers.push_back(temp.back());
            temp.pop_back();
        }
        temp.push_back(top);
    }
    return  temp;;
}

int main()
{
    int arr[5] = {1,2,3,4,5};
    vector<int> ts(arr,arr+5);
    vector<int> st= twoStacksSort(ts);

    for(int i = 0; i < st.size();i++)
        cout<<st[i]<<" ";
    while(1);
    return 0;
}
