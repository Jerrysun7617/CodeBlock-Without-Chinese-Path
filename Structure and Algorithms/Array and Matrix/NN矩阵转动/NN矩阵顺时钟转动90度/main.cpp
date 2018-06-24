#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>
using namespace std;

int main()
{
    int n = 0;
    string line = "";
    getline(cin,line);
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


        for(int y = 0; y < n;y++)
          for(int x = 0; x < n; x++)
        {
                cop[x][n-y-1] = arr[y][x];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<cop[i][j]<<" ";
            }
            cout<<endl;
        }
    //}
    while(1);
    return 0;
}
