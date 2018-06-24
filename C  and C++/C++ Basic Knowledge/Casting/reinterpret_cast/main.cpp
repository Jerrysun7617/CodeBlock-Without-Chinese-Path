#include <iostream>
using namespace std;

#define reinterpret_cast

int main()
{
    int myArray[5]={0,1,2,3,4};
    char myChar[5]={'H','a','o','Y','u'};


    int *aPoint = myArray;
    char *bPoint = myChar;

    for(int i=0;i<5;i++)
    {
#ifdef reinterpret_cast
        cout<<*(aPoint++) <<"--------" <<reinterpret_cast<unsigned long>(aPoint)<<endl;
#else
        cout<<*(aPoint++) <<"--------" <<(aPoint)<<endl;
#endif
    }

    cout <<"-------------------------"<<endl;
    for(int i=0;i<5;i++)
    {
        cout.clear();
#ifdef reinterpret_cast
        cout<<*(bPoint++) <<"-------"<<reinterpret_cast<unsigned long>(bPoint)<<endl;
#else
       cout<<*(bPoint++) <<"-------"<<(bPoint)<<endl;
#endif
    }

    system("pause");
    return 0;
}
