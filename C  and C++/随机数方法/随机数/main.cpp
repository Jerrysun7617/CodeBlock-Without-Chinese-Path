#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <vector>
using namespace std;
/*
Ҫȡ��[a,b)�����������ʹ��(rand() % (b-a))+ a;
Ҫȡ��[a,b]�����������ʹ��(rand() % (b-a+1))+ a;
Ҫȡ��(a,b]�����������ʹ��(rand() % (b-a))+ a + 1;
*/
/****************����ظ���****************/
int get_rand(int min, int max){
    return (rand() % (max-min + 1))+ min;
}
/****************������ظ���****************/
void get_rand_no_repeat(int min, int max)
{
    vector<int> temp;
    for (int i = min; i < max; ++i)
    {
        temp.push_back(i + 1);
    }
    //�ؼ����� �� #include <algorithm>��
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
