#include <iostream>

using namespace std;

void myself_insert(int * arr, int len){
    for(int i =0; i < len; i++){
        int curr = arr[i];
        int j = i - 1; //跳到负数去了
        while(arr[j]>curr &&j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
    }
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
    myself_insert(arr,len);

    for(int i = 0; i < len; i++){
        cout<<arr[i]<<" ";
    }

    while(1);
    return 0;
}
