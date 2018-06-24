#include <iostream>
#include <vector>
using namespace std;

    int findPos(vector<int> arr, int n, int num) {
        // write code here
        int position = -1;
        if(n == 0)
            return -1;
        if(n ==1){
            if(arr[0] == num)
                return 0;
            else
                return -1;
        }

        int right = n - 1;
        int left = 0;
        int mid;
        while(left <=right){ //pay attention here
            mid = left + (right - left)/2;
             if(arr[mid] == num ){
               position = mid;
                right = mid - 1;
             }
            else if(arr[mid] < num)
                left = mid + 1;
            else
                right = mid -1;

            //else if(arr[mid]
        }
        return position;
    }
int main()
{
    int arr[8] ={1,2,3,3,4};
    vector<int> test(&arr[0],&arr[5]);

    cout<<findPos(test,5,3)<<endl;
    while(1);
    return 0;
}
