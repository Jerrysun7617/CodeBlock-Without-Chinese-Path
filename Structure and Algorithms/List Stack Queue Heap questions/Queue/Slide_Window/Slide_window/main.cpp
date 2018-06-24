#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> slide(vector<int> arr, int n, int w) {
    // write code here
    deque<int> flag;
    vector<int> slide_num;
    int i = 0;
    for(i; i < w-1;i++){
        if(flag.empty())
            flag.push_back(i);
        else{
            while(!flag.empty() && arr[i] > arr[flag.back()]){
                flag.pop_back();
            }
            flag.push_back(i);
        }
    }

    for(; i < n;i++){
        while(!flag.empty()&& i - flag.front()>= w){
            flag.pop_front();
        }
        while( !flag.empty() &&arr[i] > arr[flag.back()] )
            flag.pop_back();
        flag.push_back(i);
        slide_num.push_back(arr[flag.front()]);
    }

    return slide_num;
}

int main()
{
    vector<int> d;
    for(int i = 6; i >0 ; i--)
        d.push_back(i);

    vector<int> ans = slide(d,6,3);
    for(int i = 0; i < ans.size(); i++)
       cout<<ans[i]<<" ";

       while(1);
    return 0;
}
