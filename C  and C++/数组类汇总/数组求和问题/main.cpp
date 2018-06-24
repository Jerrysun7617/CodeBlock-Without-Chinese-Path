#include <iostream>

using namespace std;


long long  num_sum(long long  x){
    long long  sum = 0;
    long long  i = 1;
    while(x/i > 0){
        sum += x/i;
        i *= 10;
    }
    return sum;
}
int main()
{
    long long  num;
    while(cin>>num){
        long long nfront=0;
        long long nend = num;
        long long nmid =0;
        while(nfront < nend){
            nmid=nfront + (nend - nfront)/2;
            if(num_sum(nmid)< num)nfront = nmid;
            else if(num_sum(nmid)> num)nend = nmid;
            else break;
        }
        if(num_sum(nmid) != num)
            nmid = -1;
        cout<<nmid<<endl;
    }
    return 0;
}
