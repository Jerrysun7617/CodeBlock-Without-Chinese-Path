#include <iostream>
using namespace std;
#define Static_casting

#ifdef Static_casting
class A{
    public:
        A():m_a(32){}
        void foo(){
            cout<<"A: "<<m_a<<endl;
        }
        void setA(int a){
            m_a=a;
        }
    private:
        int m_a;
};
class B:public A{
    public:
        B(){
            m_b=12;
            setA(13);
        }
        void foo(){
            cout<<"B: "<<m_b<<endl;
        }
    private:
        int m_b;
};
int main()
{
    A *a=new B();
    B *b=static_cast<B*>(a);
    A *aa=static_cast<A*>(b);
    b->foo();
    aa->foo();
    delete a;

    getchar();
    return 0;
}

#else
class A{
    public:
        virtual ~A(){} //使用dynamic_cast时，必要！
};
class B:public A{
    public:
        B(){
            m_b=12;
        }
        void foo(){
            cout<<"B: "<<m_b<<endl;
        }
    private:
        int m_b;
};
int main()
{
    A *a=new B();
    B *b=dynamic_cast<B*>(a);
    b->foo();
    delete a;
    //getchar();
    system("pause");
    return 0;
}
#endif // Static_casting
