#include "iostream"
using namespace std;



class B:public A
{
public:
    void foo()
    {
        cout<<"B:foo()\n";
    }
    void pp()
     {
           cout<<"B:pp()\n";
     }
    void fun()
    {
        cout<<"function in B \n";
    }
};
int main()
{
    B b;
    A *pa=&b;
    pa->foo();//���ڴ��ڶ�̬�����Ը���ָ������͵��÷������������ָ�����͵��÷���
    pa->pp();//�����ڶ�̬������ָ�����͵���
    //pa->fun();//�����޷�����
    dynamic_cast<B*>(pa)->pp();//����ʱ��̬����ת��������ָ��B��pp����
    dynamic_cast<B*>(pa)->fun();//����ʱ��̬����ת��������ָ��B��fun����
    dynamic_cast<B*>(pa)->foo();//����ʱ��̬����ת��������ָ��B��foo����

    system("pause");

    return 0;
}
