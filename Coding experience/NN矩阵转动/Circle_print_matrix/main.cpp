#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>
using namespace std;

void print(vector<vector<int>> arr,int lc,int lr ){
    int tR  = 0,tC = 0, dR = lr - 1, dC = lc-1;


    for(;tR < lr/2;tR++,tC++,dR--,dC--){
        int curR = tR;
        int curC = tC;
        while(curC != tC){
            cout<<arr[curC++][curR]<<" ";
        }
        while(curR != tR){
            cout<<arr[curC][curR++]<<" ";
        }
        while(curC != tC){
            cout<<arr[curC--][curR]<<" ";
        }
        while(curR != tR){
            cout<<arr[curC][curR--]<<" ";
        }
    }


}

int main()
{
    int n = 0;
    string line = "";
    while(getline(cin,line)){
        string word ="";
        vector <int> Lost_news;
        stringstream ss1(line);
        while (ss1 >> word)
                Lost_news.push_back(atoi(word.c_str()));

        for(int i = 0 ; i < Lost_news.size();i++)
            if(Lost_news[i]!=0)
                n++;
        //cout<<n<<endl;
        vector<int> fir(n,0);

       for(int i = 0 ; i < n;i++){
            fir[i] = Lost_news[i];
            //cout<<fir[i]<<" ";
       }
       // cout<<n<<endl;
         vector<vector<int>> arr;
         vector<vector<int>> cop;
         cop.push_back(fir);
         arr.push_back(fir);
         int i = 1, j =0;
         for(;i < n;i++){
             //fir.clear();
             cop.push_back(fir);
             for(j = 0;j < n;j++){
                cin>>fir[j];
                //cout<<fir[j]<<" ";
             }
             arr.push_back(fir);
         }


        print(arr,n,n);
    }



    return 0;
}
