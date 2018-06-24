#include <iostream>
#include <stack>
#include <cstdio>
#include <string.h>
#include<cstdlib>
#include<ctime>
//#define random(a,b) (rand()%(b-a+1)+a)
using namespace std;
//要取得[a,b]的随机整数，使用(rand() % (b-a+1))+ a;
int get_rand(int min, int max){
    return (rand() % (max-min + 1))+ min;
}
int main()
{
    while(1){
        char str[100000]="";
        scanf("%s",str);
        stack<char> stc;
        stack<char> stac2;

        int num = strlen(str);
        int no_repeat[100];
        for(int i = 0; i < num;i++)
        {
            cout<<str[i];
            int j = rand();
            for(; j>=0;j--)
                if(i != j)
                cout<<str[j];
            for(; j<num;j++)
                if(i != j)
                cout<<str[j];
            cout<<endl;
        }

    }

    return 0;
}
