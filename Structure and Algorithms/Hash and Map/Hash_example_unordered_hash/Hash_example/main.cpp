#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    unordered_map<string,int> months;  //只能用默认格式，不能用 vector
    //插入数据
    cout<<"insert data"<<endl;
    months["january"]=31;
    months["february"] = 28;
    months["march"] = 31;
    months["september"] = 0;

    //直接使用key值访问键值对，如果没有访问到，返回0
    cout<<"september->"<<months["september"]<<endl;
    cout<<"xx->"<<months["xx"]<<endl;

    typedef unordered_map<int,int> mymap;
    mymap mapping;
    mymap::iterator it;
    mapping[2]=110;
    mapping[5]=220;
    const int x=2;const int y=3;//const是一个C语言（ANSI C）的关键字，它限定一个变量不允许被改变,产生静态作用，提高安全性。

    //寻找是否存在键值对
    //方法一：
    cout<<"find data where key=2"<<endl;
    if( mapping.find(x)!=mapping.end() ){//找到key值为2的键值对
        cout<<"get data where key=2! and data="<<mapping[x]<<endl;
    }
    cout<<"find data where key=3"<<endl;
    if( mapping.find(y)!=mapping.end() ){//找到key值为3的键值对
        cout<<"get data where key=3!"<<endl;
    }
    //方法二：
    it=mapping.find(x);
    printf("find data where key=2 ?  %d\n",(it==mapping.end()));
    it=mapping.find(y);
    printf("find data where key=3 ?  %d\n",(it==mapping.end()));

    //遍历hash table
    for( mymap::iterator iter=mapping.begin();iter!=mapping.end();iter++ ){
        cout<<"key="<<iter->first<<" and value="<<iter->second<<endl;
    }


    typedef unordered_map<vector<int>,int> keydef;

    vector<int> test01(4,0);
    vector<int> test02 = {1,1,1,1};
    vector<int> test03 = {2,2,2,2};
    vector<int> test04 = {3,3,3,3};
    int num = 0;
    //keydef[0233] = num++;

    system("pause");

    return 0;
}
