#include <iostream>
#include <map>
using namespace std;
/*最长无重复字符子串练习题*/
/*
对于一个字符串,请设计一个高效算法，找到字符串的最长无重复字符的子串长度。

给定一个字符串A及它的长度n，请返回它的最长无重复字符子串长度。保证A中字符全部为小写英文字符，且长度小于等于500。

测试样例：
"aabcb",5
返回：3
*/
int longestSubstring(string A, int n) {
    // write code here
    if(n <= 0)
        return 0;
    int num  = 0;
    char fir = A[0];
    map<char,int> records;
    records[fir]++;
    for(int i = 1; i < n ; i++){
        if(records.find(A[i]) == records.end())
            records[A[i]]++;
        else
        {
            if(records.size()>num)
                num = records.size();
            records.clear();
        }
    }
    if(records.size() > num)
        num = records.size();

    return num;
}
int main()
{
    string str="";
    while(cin>>str){
        cout<<longestSubstring(str,str.size());
    }

    return 0;
}
