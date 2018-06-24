#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
/*
链接：https://www.nowcoder.com/questionTerminal/06dbca9614084e9dba9753f99629595c
来源：牛客网

给定一个长度为N的数组，找出一个最长的单调自增子序列（不一定连续，但是顺序不能乱）
例如：给定一个长度为8的数组A{1,3,5,2,4,6,7,8}，则其最长的单调递增子序列为{1,2,4,6,7,8}，长度为6.

3
7
89 256 78 1 46 78 8
5
6 4 8 2 17

1
8
1 3 5 2 4 6 7 8
*/

#ifndef MYOWN


int getLIS(vector<int> A, int n) {

    //for(int i = 0 ; i < A.size();i++)
     //   cout<<A[i]<<" ";

    // write code here
    vector<int> num(n,1);
    vector<vector<int>> vec(n);

    if(n<=1)
        return 0;
    //cout<<num[0]<<num[1]<<endl;

    for(int i = 1; i < n;i++)
    {
        int last = 0;
        for(int j = 0;j < i ;j++)
        {
            //cout<<A[i]<<" "<<A[j]<<" "<<num[j]<<" "<<last<<endl;
            if(A[j] < A[i] && num[j] > last){ //他如果大于，最大那个增序列的最后一个值，对不起，咱就加一
                last = num[j]; //smart
                vec[i].push_back(A[j]);
               // cout<<last<<endl;
            }
        }
        //cout<<last<<endl;
        if(last != 0 ) //最后一个没进去
            vec[i].push_back(A[i]);
        num[i] = last + 1;
    }
    int biggest = num[n-1];
    int j = n-1;
    for(int i = n -2; i >=0  ;i--)
        if(num[i]>biggest){
            j = i;
            biggest = num[i];
        }
    for(int i = 0 ; i < vec[j].size();i++)
        cout<<vec[j][i]<<" ";
    cout<<endl;
    return biggest;
}

int main()
{
    int n = 0;
    while(cin>>n)
    //cin>>n;
    {
        //	vector<vector<bool>> visited(matrix.size(),vector<matrix[0].size,false>);
        vector< vector<int> > arr(n);//(n,vector<int>(n)); //例子 6 1 5 2 4 3 6
        int k  = 0;
        int input = 0;
        int j = 0;
        while(n--){
            cin>>k;
            for(int i = 0; i < k;i++){
                cin>>input;
                arr[j].push_back(input);
            }
            j++;
        }

       // for(int i = 0 ; i <arr[0].size();i++)
       //     cout<<arr[0][i]<<" ";

        for(int i = 0; i <arr.size();i++)
           getLIS(arr[i],arr[i].size());
        //while(1);
    }

    return 0;
}
#else
vector<int> dp(vector<int> seq){
    int max = 0;
    int maxpos = -1;
    int size = seq.size();
    vector<int> rec(size, 1);
    vector<int> from(size, -1);
    for (int i = 0; i < size; i++){
        for (int j = 0; j < i; j++){
            if (seq[i] > seq[j] && rec[j] + 1 > rec[i]){
                rec[i] = rec[j] + 1;
                from[i] = j;
                if (rec[i] > max){
                    maxpos = i;
                    max = rec[i];
                }
 
            }
        }
    }
 
    vector<int> ret;
 
    int curr = maxpos;
 
    while (curr >= 0){
        ret.push_back(seq[curr]);
        curr = from[curr];
    }
    reverse(ret.begin(),ret.end());
    return ret;
}
 
int main(){
    int sets;
    cin >> sets;
    for (int i = 0; i < sets; i++){
        int nums;
        cin >> nums;
        vector<int> raw(nums);
        for (int j = 0; j < nums; j++){
            cin >> raw[j];
        }
        vector<int> result = dp(raw);
        for (int j = 0; j < result.size() - 1; j++){
            cout << result[j] << " ";
        }
        cout << result[result.size() - 1] << endl;
    }
    return 0;
}

#endif // MYOWN
