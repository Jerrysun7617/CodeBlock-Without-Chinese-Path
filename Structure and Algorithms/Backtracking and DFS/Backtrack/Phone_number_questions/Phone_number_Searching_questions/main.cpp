#include <iostream>
#include <vector>
using namespace std;

    int m = 0;
    void dfs(vector<string> str,int step, string cur,vector<string> &result, vector<vector<bool>> &visited ){
            if(step == str.size()){
                    m++;
                    cout<<m<<endl;
                    result.push_back(cur);
                    return;
                }
                else{
                        for(int j = 0; j < str[step].size();j++){
                            cur.push_back(str[step][j]);
                            dfs(str,step+1,cur,result,visited);
                            cur.pop_back();
                        }
                    return ;
                }

    }
    vector<string>  getPermutation(vector<string> str, int k) {

        vector<string> results;
        cout<<"str.size(): "<<str.size()<<endl;
       vector<bool>one(3,false);
        vector< vector<bool> > visited;
        for(int i = 0; i < 8;i++)
        visited.push_back(one);
        //vector<bool> visited(8,false);
        dfs(str,0,"",results,visited);

        return results;
       // return results[k-1];
    }

int main()
{
    int n,k;

    while(cin>>n>>k){
        string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        //string charmap[8] = {"abc", "def", "ghi", "jkl", "mno", "pqr", "stu", "vwx"};
        vector<string>keynum(charmap+n,charmap+k);
        vector<string> result = getPermutation(keynum,k-n+1);

        for(int i = 0; i < result.size();i++)
            cout<<result[i]<<endl;
    }
    return 0;
}
