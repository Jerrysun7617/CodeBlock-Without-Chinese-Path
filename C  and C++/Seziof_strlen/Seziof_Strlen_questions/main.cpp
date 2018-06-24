#include <iostream>
#include <string.h>

using namespace std;
struct stc{  // empty struct size is 1
};
class cls01{ // empty class size is 1
   // virtual int test(){}
};

class cls02{ // virtual function class size is 4
   virtual int test(){}
};
class cls03{ // static function class size is 4
   static int test(){}
};
class cls04{ // static function class size is 4
   static int test;
};

void fun(char st[100])
{
     cout<<"\n\ninner funciton strlen:"<<strlen(st)<<endl;
     cout<<"inner funciton sizeof:"<<sizeof(st)<<endl;
}
int main()
{
    string name="babababa";
    cout<<name.length()<<endl;
    cout<<name.size()<<endl;

    char mail[]="haha";
    cout<<strlen(mail)<<endl;
    cout<<sizeof(mail)<<endl; // sizeof 是包含'\0'的长度

    char *psd ="lalala";
    cout<<strlen(psd)<<endl;
     cout<<sizeof(psd)<<endl; //只要是指针，他就描述的是指真的大小


        char str[]="yanguoqi";
       char *p = str;
       //sizeof是返回的保证能容纳实现所建立的最大对象的字节大小。 一共8个字符，加最后的'\o'.共9个字节。
       printf("sizeof(str) = %d\n", sizeof(str));
       //这是有效字符的个数，不把'/0'算在内。
       printf("strlen(str) = %d\n", strlen(str));
       //  这里p是一个指针型变量，在32位PC下占4个字节。一般指针都占4个字节。
       printf("sizeof(p) = %d\n", sizeof(p));
        printf("strlen(p) = %d\n", strlen(p));


     /* the parameter of strlen cannot be struct type and class types
      printf("\n\n strlen(struct stc) = %d\n", strlen(struct stc));



     /*struct type questions */
      printf("\n\n sizeof(struct stc) = %d\n", sizeof(struct stc));

      /*struct type questions */
      printf("\n\n sizeof(class cls) = %d\n", sizeof(class cls01));
        printf("\n\n sizeof(class cls) = %d\n", sizeof(class cls02));
        printf("\n\n sizeof(class cls) = %d\n", sizeof(class cls03));
        printf("\n\n sizeof(class cls) = %d\n", sizeof(class cls04));

        char st[100]= "012345678912345689";

        fun(st);
    while(1);
    return 0;
}
