#include <iostream>
#include <algorithm>

using namespace std;
#define String_reverse  /* �ַ����������ַ��������*/


/*��С�ַ��� ƴ������
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


/* �ַ�����λ��ϵ
"ABCDE",5,3
���أ�"DEABC"*/
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
    /* �ַ����������ַ��������*/
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
