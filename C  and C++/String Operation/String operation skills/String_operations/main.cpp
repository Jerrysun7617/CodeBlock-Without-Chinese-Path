#include <iostream>
#include <algorithm>

using namespace std;
#define String_reverse  /* 字符串中所有字符逆序操作*/


/*最小字符串 拼接问题
["abc","de"],2
"abcde" */
    static bool cmp(const string& str1, const string& str2){
        return str1 + str2 < str2 + str1 ? true : false;
    }
   string findSmallest(vector<string> strs, int n) {
        //write code here
        sort(strs.begin(), strs.end(), cmp);
        string result;
        for(int i = 0; i < strs.size(); ++i){
            result += strs[i];
        }
        return result;
    }


/* 字符串移位联系
"ABCDE",5,3
返回："DEABC"*/
    string stringTranslation(string A, int n, int len) {
        reverse(A.begin(), A.begin()+len);  // ABCDE  -- CBADE
        reverse(A.begin()+len, A.end());    // CBAED
        reverse(A.begin(), A.end());       // DEABC
        return A;
    }
    string stringTranslation(string A, int n, int len) {
        return (A+A).substr(len,n);
        // write code here
    }


#ifdef String_reverse
    /* 字符串中所有字符逆序操作*/
    string reverseSentence(string A, int n) {
        // write code here
        reverse(A.begin(),A.end());
        int i,j;
        for(i = 0; i < n; i ++){
            j = i;
            while(j < n && A[j] != ' '){
                j++;
            }
            reverse(A.begin() + i,A.begin() + j);
            i = j;
        }
        return A;
    }
#endif

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
