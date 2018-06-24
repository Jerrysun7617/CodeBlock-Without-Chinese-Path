//description: 演示String::compare函数的用法，比较两个字符串是否相等？
//compile: g++ -g compare_string.cc -o compare_string

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


     string s;
    char str[256];
    getline(cin, s);
    //cin.getline(str, sizeof(str));

    string s;
    char str[256];

     while(gets(str)){
    //cin.getline(str, sizeof(str));
        cout<<str<<endl;

    }

int main(int argc, char* argv[])
{
    string str1("green apple");
    string str2("red apple");
    string str3("apple");

    if(str3.compare("apple") == 0)
        cout << str3 << " is an apple!" << endl;

    if(str1.compare(str2) !=0)
        cout << str1 << " is not " << str2 << endl;

    if(str1.compare(6, 5, "apple") == 0)
        cout << "still, " << str1 << " is an apple!" << endl;

    if(str2.compare(str2.size() - 5, 5, "apple") == 0)
        cout << "and " << str2 << " is also an apple!" << endl;

    if(str1.compare(6, 5, str2, 4, 5) == 0)
        cout << "therefore, both are apples!" << endl;

    while(1);
    return 0;
}

/*  sort(begin,end)
int main()
{
     int a[20]={2,4,1,23,5,76,0,43,24,65},i;
     for(i=0;i<sizeof(a)/sizeof(int);i++)
      cout<<a[i]<<" ";
     sort(a,a+20);
     cout<<endl;
     for(i=0;i<sizeof(a)/sizeof(int);i++)
     cout<<a[i]<<" ";
     cout<<endl;
     while(1);
     return 0;
}
*/


    bool compare011(int a,int b)
    {
          return a>b;   //升序排列，如果改为return a>b，则为降序
    }
    int main()
    {
         int a[20]={2,4,1,23,5,76,0,43,24,65},i;
         for(i=0;i<20;i++)
           cout<<a[i]<<" ";
           cout<<endl;
         sort(a,a+20,compare011);
         for(i=0;i<20;i++)
           cout<<a[i]<<" ";
           cout<<endl;
           while(1);
         return 0;
    }

/*
    enum Enumcomp{ASC,DESC};
    class compare
    {
          private:
                Enumcomp comp;
          public:
                compare(Enumcomp c):comp(c) {};
          bool operator () (int num1,int num2)  //()operator overload
             {
                switch(comp){
                     case ASC:
                            return num1<num2;
                     case DESC:
                            return num1>num2;
                  }
              }
    };
    int main()
    {
         int a[20]={2,4,1,23,5,76,0,43,24,65},i;
         for(i=0;i<20;i++)
             cout<<a[i]<<" ";
         cout<<endl;
         sort(a,a+20,compare(DESC));
         for(i=0;i<20;i++)
             cout<<a[i]<<" ";
        cout<<endl;
        while(1);
         return 0;
    }

    */
    /*
    int main()
    {
          int a[20]={2,4,1,23,5,76,0,43,24,65},i;
          for(i=0;i<20;i++)
              cout<<a[i]<<" ";
          cout<<endl;
          sort(a,a+20,greater<int>());
          for(i=0;i<20;i++)
              cout<<a[i]<<" ";
            cout<<endl;
            while(1);
          return 0;
    }
    */
    int main()
    {
         string str("cvicses");
         string s(str.rbegin(),str.rend());
         cout << s <<endl;
         while(1);
         return 0;
    }
#endif
