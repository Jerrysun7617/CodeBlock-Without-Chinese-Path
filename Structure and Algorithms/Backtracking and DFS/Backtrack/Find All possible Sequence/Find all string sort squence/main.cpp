#include <iostream>
#include <vector>
using namespace std;

    int m = 0;
    void dfs(string &str,int step, string cur,string &result, vector<bool> &visited ,int k){
            if(step == str.size()){
                    if(m == k)
                        result = cur;
                    cout<<cur<<endl;
                    m++;
                    return;
                }
                else{
                    if(m <=k)
                        for(int i = 0; i < str.size(); i++){
                            if(visited[i] == false){
                                visited[i] = true;
                                cur.push_back(str[i]);
                                dfs(str,step+1,cur,result,visited,k);
                                cur.pop_back();
                                visited[i] = false;
                            }
                        }
                    return ;
                }

    }
    string getPermutation(int n, int k) {
        string str = "";

        for(int i = 1; i < n+1;i++){
            str += i + '0';
        }

        if(n == 1)
            return str;
        if(n == 2)
        {
            if(k == 0)
                return "12";
            else
                return "21";
        }
        string results;
        vector<bool> visited(str.size(),false);
        m = 0;
        dfs(str,0,"",results,visited,k);

        return results;
       // return results[k-1];
    }

int main()
{
    int n,k;

    while(cin>>n>>k){
         string charmap[8] = {"abc", "def", "ghi", "jkl", "mno", "pqr", "tuv", "wxy"};
       //vector<string>(charmap,8);

        getPermutation(n,k);
        cout<<m<<endl;
    }
    return 0;
}
