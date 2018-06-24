#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> buildMaxTree(vector<int> A, int n) {
    // write code here
     vector<pair<int, int>> pvec(n);
    vector<int> res;
    stack<int> lsta, rsta;
    for (int i = 0;i < n;++i)
    {
        while (!lsta.empty() && A[lsta.top()] <= A[i])
            lsta.pop();
        if (lsta.empty())
            pvec[i].first = -1;
        else
            pvec[i].first = lsta.top();
        lsta.push(i);
    }

    for (int j = n-1;j >= 0;--j)
    {
        while (!rsta.empty() && A[rsta.top()] <= A[j])
            rsta.pop();
        if (rsta.empty())
            pvec[j].second = -1;
        else
            pvec[j].second = rsta.top();
        rsta.push(j);
    }
    for (const auto &pa : pvec)
    {
        //cout<<pa.first<<" "<<pa.second<<endl;
        if (pa.first == -1 && pa.second == -1)
            res.push_back(-1);
        else if (pa.first == -1)
            res.push_back(pa.second);
        else if (pa.second == -1)
            res.push_back(pa.first);
        else
        {
            int index = A[pa.first] > A[pa.second] ? pa.second : pa.first;
            res.push_back(index);
        }
    }
    return res;
}

int main()
{
    int arr[4] = {3,1,4,2};
    vector<int> d(arr,arr+4);
    //for(int i = 0; i <6 ; i++)
     //   d.push_back(i);

    vector<int> ans = buildMaxTree(d,d.size());
    for(int i = 0; i < ans.size(); i++)
       cout<<ans[i]<<" ";

       while(1);
    return 0;
}
