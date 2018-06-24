#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <vector>
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
void get_rand_no_repeat(int min, int max)
{
    vector<int> temp;
    for (int i = min; i < max; ++i)
    {
        temp.push_back(i + 1);
    }
    //关键函数 在 #include <algorithm>里
    random_shuffle(temp.begin(), temp.end());

    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
    cout<<endl;
}
int main()
{
    int i;
    int a = 1, b =3;
    string str = "abc";
    char tem[40000] = "abc";
    vector<string> keep;
     i  = 100;
    while(i--){
        get_rand_no_repeat(5, 10000);
    }
    return 0;
}
