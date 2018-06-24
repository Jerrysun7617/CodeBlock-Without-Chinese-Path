#include <iostream>
#include <vector>
using namespace std;
/*
题目是这样的，
1 -1 -10 9 11 -4 6 20 -10 5 -9
最长增片段是9 11 -4 6 20
*/
int main()
{
    int n = 0;
    //int test[10] ={1,-1,-10,4,11,-6,9,20,-10,11};

    while(cin>>n){
        vector<int> test(n,0);
          for(int i = 0; i < n; i++)
                cin>>test[i];

         int keep =0;
         if(test[0] > 0)
            keep = test[0];
            vector<int> vec;
         for(int i = 1; i < n;i++)
         {
             if(test[i] >= 0){
                keep += test[i];
                if(i == n-1)
                    vec.push_back(keep);
             }
             else{
                //less  than  0
                if(i == n-1){
                    vec.push_back(keep);
                    keep = 0;
                }
                else{
                    //可能的都放进去
                    if(test[i] + keep > 0){
                        vec.push_back(keep); //keep接着走，有戏
                        keep += test[i];
                    }
                    else{
                         vec.push_back(keep);
                         keep = 0;
                    }
                }
             }
         }

         int  biggest = vec[0];
         for(int i = 1; i < vec.size(); i++){
            if(vec[i] > biggest)
                biggest = vec[i];
         }
        cout<<biggest<<endl;
    }
    while(1);
    return 0;
}
