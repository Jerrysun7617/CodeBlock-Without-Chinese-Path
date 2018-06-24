#include <iostream>

using namespace std;
int merge_data(int * arr,int left,int mid,int right){
    int length = right-left+1;
    int * arr_cpy = new int[length];
    for(int i = 0, j = left;i < length;i++,j++)
        arr_cpy[i] = arr[j];

    int i = 0;
    int j = mid-left+1; //分成两块
    int k = left;
    for(;i <= mid-left && j<=length -1;k++){
        if(arr_cpy[i] < arr_cpy[j])
            arr[k] = arr_cpy[i++];
        else
            arr[k] = arr_cpy[j++];
    }
    while(i <= mid-left)
        arr[k++] = arr_cpy[i++];
    while(j<=length-1)
        arr[k++] = arr_cpy[j++];

    delete arr_cpy;
}
void merge_sort(int* arr, int left,int right){
    if(left<right){
        int mid = left + (right  - left) / 2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right); //  先分开

        merge_data(arr, left,mid,right); //在合并
    }
}
void myself_gubing(int * arr, int len){
    merge_sort(arr,0,len-1);
}
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
    myself_gubing(arr,len);

    for(int i = 0; i < len; i++){
        cout<<arr[i]<<" ";
    }

    while(1);
    return 0;
}
