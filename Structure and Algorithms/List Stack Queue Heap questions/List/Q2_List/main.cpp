
#include <iostream>
#include <list>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

/*
STL中提供的list类，是一个双向循环链表类。从每一个元素（节点），都可以访问前面一个元素和后面一个元素。
在STL中，list提供了一系列的成员函数，实则完成的就是链表中的基本运算，以及其他在数据结构中不作为基本运算，
但在工程中常用到的功能。
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

    list1.reverse();  // 可以反转

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
