#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;
/*
要取得[a,b)的随机整数，使用(rand() % (b-a))+ a;
要取得[a,b]的随机整数，使用(rand() % (b-a+1))+ a;
要取得(a,b]的随机整数，使用(rand() % (b-a))+ a + 1;
*/
/****************随机重复数****************/
int get_rand(int min, int max){
    return (rand() % (max-min + 1))+ min;
}
/****************随机无重复数****************/
string get_all_string(char * tem, int max)
{
    vector<int> temp;
    char * str  = new char[max+1];

    for (int i = 0; i < max; ++i)
    {
        str[i]=' ';
        temp.push_back(i);
    }
    //关键函数 在 #include <algorithm>里
    random_shuffle(temp.begin(), temp.end());

    for (int i = 0,k = 0; i < temp.size(); i++)
    {
        str[k++] = tem[temp[i]];
    }

    for (int i = 0,k = 0; i < temp.size(); i++)
    {
        tem[i] = str[i];
    }
    string anwser  = tem;

    //cout<<str<<"   "<<max<<"   "<<temp.size()<<endl;
    //delete str;

    return anwser;
}
int main()
{
    char tem[40000] = "abc";

    while(scanf("%s",tem)){
            vector<string> keep;
        for(int i = 0 ; i < 1000;i++){
            string str  = "";
            str = get_all_string(tem, strlen(tem));

            vector <string>::iterator intor;
            int flag = 1;
            for(intor = keep.begin(); intor < keep.end();intor++)
                if(str == *intor)
                    flag = 0;

            if(flag){
                cout<<str<<endl;
                keep.push_back(str);
            }
        }
    }
    return 0;
}
