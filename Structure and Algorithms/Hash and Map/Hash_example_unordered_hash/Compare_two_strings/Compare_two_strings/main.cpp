#include <iostream>
#include <unordered_map>
using namespace std;
//两个hash_map的比较

bool chkRotation(string A, int lena, string B, int lenb) {
    // write code here
    if(lena != lenb)
        return false;
    string C = A+A;
    if(C.find(B)!=string::npos)
        return true;
    else
        return false;
}
bool chkTransform(string A, int lena, string B, int lenb) {
    // write code her
    if(lena != lenb)
        return false;
    unordered_map<char,int> map1;
    unordered_map<char,int> map2;

    for(int i = 0; i < lena;i++)
        map1[A[i]]++;
    for(int i = 0; i < lenb;i++)
        map2[B[i]]++;

    for( auto itr = map1.begin();itr != map1.end();itr++){
        if(itr->second != map2[itr->first])  //两个hash_map的比较
            return false;
    }
    return true;
}
int main()
{
    string str1 = "abc";
    string str2 = "dac";

  while(cin>>str1>>str2){
        cout<<chkTransform(str1,str1.size(),str2,str2.size())<<endl;

  }
    return 0;
}
