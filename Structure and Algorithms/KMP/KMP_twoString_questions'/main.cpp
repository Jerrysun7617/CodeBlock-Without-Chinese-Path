#include <iostream>

using namespace std;
    void get_next(string & str,int *next,int n)          //  to  next point
    {
        next[0] = -1;
        int k = -1;
        for(int i = 1;i<n;i++)
        {
            while(k>-1 && str[k+1] != str[i])
                k=next[k];
            if(str[k+1] == str[i])
                k++;
            next[i] = k;
        }
    }
    int KMP(string &str,int slen,string &ptr,int plen)        // kmp
    {
        int *next = new int[plen];
        get_next(ptr,next,plen); //得到plen 的next指针
        int k = -1;
        for(int i = 0;i<slen;i++)
        {
            while(k>-1 && ptr[k+1] != str[i])
                k=next[k];
            if(ptr[k+1] == str[i])
                k++;
            if(k == plen -1 )
            {
                return i-plen+1;
            }
        }
        return -1; //否则就是没找到
    }

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
