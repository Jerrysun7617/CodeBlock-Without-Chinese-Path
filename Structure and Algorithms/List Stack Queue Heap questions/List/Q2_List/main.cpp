
#include <iostream>
#include <list>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

/*
STL���ṩ��list�࣬��һ��˫��ѭ�������ࡣ��ÿһ��Ԫ�أ��ڵ㣩�������Է���ǰ��һ��Ԫ�غͺ���һ��Ԫ�ء�
��STL�У�list�ṩ��һϵ�еĳ�Ա������ʵ����ɵľ��������еĻ������㣬�Լ����������ݽṹ�в���Ϊ�������㣬
���ڹ����г��õ��Ĺ��ܡ�
*/

struct st_user
{
    int id;
};

int main()
{

    st_user a1,a2,a3;

    a1.id = 1;
    //printf(a1.name,"%s","xxxxxxxxx");
    a2.id = 2;
    //printf(a2.name,"%s","fff");
    a3.id = 3;
    //printf(a3.name,"%s","bbbb");

    list<st_user> list1;

    list1.push_back(a1);
    list1.push_back(a2);
    list1.push_back(a3);

    list1.reverse();  // ���Է�ת

    vector<int> test(5,0);
    reverse(test.begin(),test.end());

    printf("------------------------------\n");


    for(list<st_user>::iterator iter = list1.begin(); iter != list1.end(); ++iter)
    {
        printf("%d \n", (iter)->id);
    }


    printf("------------------------------\n");


    for(list<st_user>::iterator iter = list1.begin(); iter != list1.end();)
    {
        if( (iter)->id == 2 )
        {
            iter = list1.erase(iter);
        }
        else
            ++iter;

    }

    printf("------------------------------\n");


    for(list<st_user>::iterator iter = list1.begin(); iter != list1.end(); ++iter)
    {
        printf("%d \n", (iter)->id);
    }


    printf("------------------------------\n");


    system("pause");


    return 0;
}
