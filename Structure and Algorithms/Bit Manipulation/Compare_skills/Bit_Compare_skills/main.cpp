#include <iostream>

using namespace std;
  int getMax(int a, int b) {
        // write code here
        int i = 0x80000000;
        int ka = a;
        int kb = b;
        /*
        if(a&i != 0 && b&i != 0)
        {
            ka = 0-b;
            kb = 0-a;
        }
        else{
            if(a&i != 0)
                return b;
            else
                return a;
        }
        */
        i >>= 1;
        while(i){
            printf("%X  %X\n",ka&i,kb&i);
            if( (kb&i != ka&i))
            {
                i >>= 1;
                printf("i = %X\r\n",i);
            }

            else
            {
                if(kb&i == 0)
                    return a;
                else
                    return b;
            }
        }
        return a;
}
int main()
{
    cout << "Hello world!" << endl;
    int i = 444;
    int j = 555;
    int f = 0x80000000;

    printf("%X  %X\n",i&f,j&f);

    cout<<getMax(i,j)<<endl;
    int k = 0x00000001;
    if(i & k == k)
        cout<<"hello "<<endl;
    while(1);
    return 0;
}
