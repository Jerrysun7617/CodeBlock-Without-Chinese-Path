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
    cout<<sizeof(mail)<<endl; // sizeof �ǰ���'\0'�ĳ���

    char *psd ="lalala";
    cout<<strlen(psd)<<endl;
     cout<<sizeof(psd)<<endl; //ֻҪ��ָ�룬������������ָ��Ĵ�С


        char str[]="yanguoqi";
       char *p = str;
       //sizeof�Ƿ��صı�֤������ʵ������������������ֽڴ�С�� һ��8���ַ���������'\o'.��9���ֽڡ�
       printf("sizeof(str) = %d\n", sizeof(str));
       //������Ч�ַ��ĸ���������'/0'�����ڡ�
       printf("strlen(str) = %d\n", strlen(str));
       //  ����p��һ��ָ���ͱ�������32λPC��ռ4���ֽڡ�һ��ָ�붼ռ4���ֽڡ�
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
