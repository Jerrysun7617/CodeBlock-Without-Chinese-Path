#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int getMin(vector<int> arr, int n) {
    // write code here
    if(arr.empty() || n == 0)
        return -1;
    int low = 0;
    int high = n -1;
    int mid = 0;
    while(low < high){

        if(low == high - 1) // only one number
            break;
        if(arr[low] < arr[high])
            return arr[low];

         mid = low + (high - low)/2;

        if(arr[low] > arr[mid])
            high = mid;
        else if(arr[mid] > arr[high])
            low = mid;
        while(low < mid)  // equal to right or left // only two numbers
        {
            if(arr[low] == arr[mid])
                low++;
            else if (arr[low] < arr[mid])
                return arr[low];
            else{
                high = mid;
                break;
            }
        }

    }
    //cout<<min(arr[low],arr[high])<<endl;
    return min(arr[low],arr[high]);
}
int main()
{
    int arr[8] ={3,4,1,2,3};
    vector<int> test(&arr[0],&arr[5]);

    cout<<getMin(test,5)<<endl;
    while(1);
    return 0;
}
