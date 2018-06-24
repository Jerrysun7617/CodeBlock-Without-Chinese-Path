#include<iostream>
#include<deque>
using namespace std;

int main()
{
    deque<int> d;
    for(int i = 1; i < 6; i ++)
        d.push_back(i);

    d.pop_front();
    d.pop_front();

    deque<int>::iterator it;
    for(it = d.begin(); it != d.end(); it ++)
        cout<<*it<<" ";
    cout<<endl;

    d.pop_back();
    for(it = d.begin(); it != d.end(); it ++)
        cout<<*it<<" ";
    cout<<endl;

    d.erase(d.begin()+1);
    for(it = d.begin(); it != d.end(); it ++)
        cout<<*it<<" ";
    cout<<endl;

    d.clear();
    cout<<d.size()<<endl;

    while(1);

    return 0;
}
