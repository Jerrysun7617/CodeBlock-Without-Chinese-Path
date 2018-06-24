#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>
#include <string>
#include <hash_map>
#include <map>
using namespace std;
using namespace __gnu_cxx;
/*
bool no_find_vector(vector<vector<int>> ent, vector<int> cur){
    bool tr = true;
    if(ent.empty())
        return tr;

    vector<vector<int>>::iterator itr;

    for(  itr  = ent.begin(); itr < ent.end(); itr++)
    {
        vector<int> test = *itr;
        if(test[0] == cur[0] && test[1] == cur[1]&& test[2] == cur[2])
            break;
    }
    if(itr != ent.end())
         tr = false;
    return tr;
}*/

vector<vector<int>> threeSum(vector<int> &arr) {
    vector<vector<int>> vec;
#ifdef Map
    unordered_map<string,int> mymap;
    int num = 0;
#endif
    int size = arr.size();
    sort(arr.begin(),arr.end());

    for(int i =0; i < size;i++){
        if(i == 0 || arr[i] != arr[i-1]){
                int right = size -1;
                int mid = i+1;
                while(mid < right)
                {
                    while(mid<right &&  arr[i] + arr[mid] + arr[right] > 0) right--;
                        if (mid < right && arr[i] + arr[mid] + arr[right] == 0){
                            vector<int> temp(3);
                            temp[0] = arr[i];
                            temp[1] = arr[mid];
                            temp[2] = arr[right];
                            vec.push_back(temp);
#ifdef Map
                            string st = "";
                            st =  to_string(arr[i])+" "+to_string(arr[mid]) +" "+to_string(arr[right]);

                            unordered_map<string,int>::iterator itr;
                            itr = mymap.find(st);
                            if(itr == mymap.end()){
                                mymap[st] = num++;
                                vec.push_back(temp);
                                //cout<<mem[0]<<" "<<mem[1]<<" "<<mem[2]<<endl;
                            }
#endif
                            while(mid < right && arr[mid] == temp[1])
                                mid++;
                    } else { // num[i] + num[left] + num[right] < 0的情况，left右移，增大num[left]的值
                        mid++;
                    }
                }
            }
        }
        return vec;
}
int main()
{
    int k = 0;
    while(cin>>k){
        vector<int> num;
        for(int i = 0; i < k;i++){
            int s = 0;
            cin>>s;
            num.push_back(s);
        }


        vector<vector<int>> result= threeSum(num);

        for(vector<vector<int>>::iterator itr = result.begin();itr < result.end() ;itr++)
        {
            vector<int> tr =*itr;
            cout<<tr[0]<<" "<<tr[1]<<" "<<tr[2]<<endl;
        }
    }
    return 0;
}
