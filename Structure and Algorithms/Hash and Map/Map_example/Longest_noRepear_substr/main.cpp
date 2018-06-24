#include <iostream>
#include <map>
using namespace std;
/*����ظ��ַ��Ӵ���ϰ��*/
/*
����һ���ַ���,�����һ����Ч�㷨���ҵ��ַ���������ظ��ַ����Ӵ����ȡ�

����һ���ַ���A�����ĳ���n���뷵����������ظ��ַ��Ӵ����ȡ���֤A���ַ�ȫ��ΪСдӢ���ַ����ҳ���С�ڵ���500��

����������
"aabcb",5
���أ�3
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
