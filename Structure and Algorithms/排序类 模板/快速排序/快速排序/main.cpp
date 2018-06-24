#include <iostream>

using namespace std;
#ifdef C++patter
int partition_array(vector<int> &arr,int left,int right){
    int pivot = arr[left]; //中轴
    while(left < right){
        while(left<right && arr[right] >= pivot){
            --right;
        }
        arr[left] = arr[right];//直到找到小的就交换
        while(left <right && arr[left] <= pivot){
            left++;
        }
        arr[right] = arr[left];
    }
    arr[left] = pivot;
    return left;
}
void quick_sort(vector<int> &arr, int left,int right){
    if(left < right){
        int q = partition_array(arr,left,right);
        quick_sort(arr,left,q-1);
        quick_sort(arr,q+1,right);
    }
}
void myself_quicksort(vector<int> &arr, int len){
    quick_sort(arr,0,len-1);
}
#else
int partition_array(int * arr,int left,int right){
    int pivot = arr[left]; //中轴
    while(left < right){
        while(left<right && arr[right] >= pivot){
            --right;
        }
        arr[left] = arr[right];//直到找到小的就交换
        while(left <right && arr[left] <= pivot){
            left++;
        }
        arr[right] = arr[left];
    }
    arr[left] = pivot;
    return left;
}
void quick_sort(int* arr, int left,int right){
    if(left < right){
        int q = partition_array(arr,left,right);
        quick_sort(arr,left,q-1);
        quick_sort(arr,q+1,right);
    }
}
void myself_quicksort(int * arr, int len){
    quick_sort(arr,0,len-1);
}
#else
int main()
{
    cout << "Hello world!" << endl;
    int len =0;
    int arr[1000];
    cin>>len;
    for(int i = 0; i < len; i++){
        cin>>arr[i];
//cout<<arr[i];
    }
    myself_quicksort(arr,len);

    for(int i = 0; i < len; i++){
        cout<<arr[i]<<" ";
    }

    while(1);
    return 0;
}
