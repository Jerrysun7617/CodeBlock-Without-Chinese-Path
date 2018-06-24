#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>
using namespace std;

void Circle_print(int arr[][5],int lc,int lr ){
    int tR  = 0,tC = 0, dR = lr - 1, dC = lc-1;


    for(;tR <= lr/2;tR++,tC++,dR--,dC--){
        int curR = tR;
        int curC = tC;
        if(curR == dR)
        {
            while(curC <= dC)
                cout<<arr[curR][curC++]<<" ";
            break;
        }
        if(curC == dC)
        {
            while(curR <= dR)
                cout<<arr[curR++][curC]<<" ";
            break;
        }
        while(curC != dC){
            cout<<arr[curR][curC++]<<" ";
        }
        while(curR != dR){
            cout<<arr[curR++][curC]<<" ";
        }
        while(curC != tC){
            cout<<arr[curR][curC--]<<" ";
        }
        while(curR != tR){
            cout<<arr[curR--][curC]<<" ";
        }
    }
}

void only_print(int arr[][5],int curC, int curR,int dC, int dR, bool jud){
    if(jud){
        while(curR != dR+1)
            cout<<arr[curR++][curC--]<<" ";
    }else{
        while(dR != curR -1)
            cout<<arr[dR--][dC++]<<" ";
    }
}
void Z_print(int arr[][5],int lc,int lr){
    int tR  = 0,tC = 0, dR = lr -1, dC = lc -1;

    int curR = tR;
    int curC = tC;
    bool mark = false;
    int i = 0 ;
    int changes = 0;
    while(curR < dR+1){
        //make sure the top points
        only_print(arr,curC,curR,tC,tR,mark);
        curR =  curC == dC? curR+1:curR;
        curC =  curC == dC? curC:curC+1;
        tC = tR ==dR? tC+1:tC;
        tR = tR == dR? tR: tR+1;
         mark = !mark;
        //cout<<mark<<endl;
    }
}
int main()
{
    int n = 0;
    string line = "";
    while(cin>>n){
        int test[6][5] = {
        {1,2,3,4,5},
        {6,7,8,9,10},{
        11,12,13,14,15},
        {16,17,18,19,20},{
        21,22,23,24,25},
        {26,27,28,29,30},
        };


        Z_print(test,5,6);
    }

    return 0;
}
