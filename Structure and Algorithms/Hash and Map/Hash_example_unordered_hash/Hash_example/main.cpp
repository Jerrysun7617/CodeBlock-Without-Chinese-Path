#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    unordered_map<string,int> months;  //ֻ����Ĭ�ϸ�ʽ�������� vector
    //��������
    cout<<"insert data"<<endl;
    months["january"]=31;
    months["february"] = 28;
    months["march"] = 31;
    months["september"] = 0;

    //ֱ��ʹ��keyֵ���ʼ�ֵ�ԣ����û�з��ʵ�������0
    cout<<"september->"<<months["september"]<<endl;
    cout<<"xx->"<<months["xx"]<<endl;

    typedef unordered_map<int,int> mymap;
    mymap mapping;
    mymap::iterator it;
    mapping[2]=110;
    mapping[5]=220;
    const int x=2;const int y=3;//const��һ��C���ԣ�ANSI C���Ĺؼ��֣����޶�һ�������������ı�,������̬���ã���߰�ȫ�ԡ�

    //Ѱ���Ƿ���ڼ�ֵ��
    //����һ��
    cout<<"find data where key=2"<<endl;
    if( mapping.find(x)!=mapping.end() ){//�ҵ�keyֵΪ2�ļ�ֵ��
        cout<<"get data where key=2! and data="<<mapping[x]<<endl;
    }
    cout<<"find data where key=3"<<endl;
    if( mapping.find(y)!=mapping.end() ){//�ҵ�keyֵΪ3�ļ�ֵ��
        cout<<"get data where key=3!"<<endl;
    }
    //��������
    it=mapping.find(x);
    printf("find data where key=2 ?  %d\n",(it==mapping.end()));
    it=mapping.find(y);
    printf("find data where key=3 ?  %d\n",(it==mapping.end()));

    //����hash table
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
