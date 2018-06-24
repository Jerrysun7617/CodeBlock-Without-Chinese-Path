#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int getLIS(vector<int> A, int n) {
    // write code here
    vector<int> num(n,1);

    if(n<=1)
        return 0;
    //cout<<num[0]<<num[1]<<endl;

    for(int i = 1; i < n;i++)
    {
        int last = 0;
        for(int j = 0;j < i ;j++)
        {
            cout<<A[i]<<" "<<A[j]<<" "<<num[j]<<" "<<last<<endl;
            if(A[j] < A[i] && num[j] > last){ //他如果大于，最大那个增序列的最后一个值，对不起，咱就加一
                last = num[j]; //smart
               // cout<<last<<endl;
            }
        }
        num[i] = last + 1;
    }
    int biggest = num[0];
    for(int i = 1; i < n;i++)
        biggest = max(num[i],biggest);
    return biggest;
}

int main()
{
    cout << "Hello world!" << endl;

    int n = 0;
    while(cin>>n){
        vector<int> A(n,0); //例子 6 1 5 2 4 3 6
        for(int i = 0; i < n;i++)
            cin>>A[i];
        cout<<getLIS(A,n)<<endl;
    }

    return 0;
}
