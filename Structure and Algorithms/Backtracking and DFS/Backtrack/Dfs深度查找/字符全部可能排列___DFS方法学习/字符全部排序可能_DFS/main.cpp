#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class solution{
public:
  static vector<string> solve(const char* s, int size){
     vector<string> ans;
    if(s==0) return ans;

    vector<bool> visited(size,false);
    bfs(s,0,ans,"   ",visited,size);

    return ans;
  }
  static void bfs(const char* s, int depth, vector<string>& ans,string an, vector<bool>& visited,int size){
    if(depth>=size){ //find the depth
      ans.push_back(an);
      return;
    }
    for(int i=0;i<size;i++){
      if(visited[i]==false){
            an.push_back(s[i]);
            visited[i]=true;
            //cout<<"s["<<i<<"]: "<<s[i]<<endl;
            bfs(s,depth+1,ans,an,visited,size);
            //cout<<"i:"<<i<<", an:"<<an.back()<<endl;
            an.pop_back();
            visited[i]=false;
      }
    }
  }
};

int main(){
  const char* s="abc";
  vector<string> ans = solution::solve(s,3);

  for(string s: ans)
    cout<<s<<endl;

   while(1);
  return 0;
}
