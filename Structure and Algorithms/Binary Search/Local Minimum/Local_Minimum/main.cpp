#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /*
    int getLess(int[] arr, int left, int right) {
        while (left <= right) {
            int mid = left+(right-left)/2;
            if (arr[mid+1] > arr[mid] && arr[mid-1] > arr[mid]) {
                return mid;
            }else if (arr[mid] > arr[mid-1]) {
                right = mid-1;
            }else if (arr[mid] > arr[mid+1]) {
                left = mid+1;
            }
        }
    }*/
    int getLessIndex(vector<int> arr) {
        int sz = arr.size();
        if(sz <= 1)
            return 0;
        int position = 0;
        if(arr[0] < arr[1])
            position = 0;
        else if (arr[sz -1] < arr[sz - 2])
            position = sz - 1;
        else{
            int right = sz-1;
            int left = 0;
            int mid = left + (right - left)/2;

            while(left <= right){
                if(arr[mid] < arr[mid+1] && arr[mid] < arr[mid-1])
                    break;
                if(arr[mid] > arr[mid-1]){
                    right = mid;
                }
                else if( arr[mid] > arr[mid+1])
                    left = mid;
                mid = left + (right - left)/2;
            }
            position = mid;
        }
        return position;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    int arr[8] ={6,3,2,7,4,9,6,8};
    vector<int> test(&arr[0],&arr[8]);
    class Solution sl;
    //cout<<test.size()<<endl;
    cout<<sl.getLessIndex(test)<<endl;


    while(1);
    return 0;
}
