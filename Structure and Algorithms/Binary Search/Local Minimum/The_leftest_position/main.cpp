#include <iostream>
#include <vector>
using namespace std;

int findPos(vector<int> arr, int n) {
    // write code here
    int pos = -1;
    if(arr.empty() || n == 0)
        return -1;
    //
    if(arr[0] > n || arr[n-1]<0)
        return -1;
    int left = 0;
    int right = n - 1;
    int mid = 0;
    while(left <= right){
        //if(left == arr[left])
        mid = left + (right - left)/2;
        if(arr[mid] >  mid)
        {
            right = mid -1;
        }
        else if(arr[mid] < mid){
            left = mid + 1;
        }
        else{
            pos = mid;
            right = mid - 1;
        }
    }

    return pos;
}
int main()
{
   int arr[8] ={0,1,2,3,5};
    vector<int> test(&arr[0],&arr[5]);

    cout<<findPos(test,5)<<endl;
    while(1);
    return 0;
}
