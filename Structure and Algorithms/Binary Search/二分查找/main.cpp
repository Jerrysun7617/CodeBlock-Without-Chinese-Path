#include<iostream>
#define N 10
using namespace std;
int main()
{
     int a[N],front,end,mid,x,i;
     cout<<"请输入已排好序的a数组元素:"<<endl;
     for(i=0;i<N;i++)
              cin>>a[i];
     cout<<"请输入待查找的数x:"<<endl;
     cin>>x;
     front=0;
     end=N-1;
     mid=(front+end)/2;
     while(front<end&&a[mid]!=x)
     {
        if(a[mid]<x)front=mid+1;
        if(a[mid]>x)end=mid-1;
        mid=(front+end)/2;
     }
     if(a[mid]!=x)
          printf("没找到！\n");
     else
          printf("找到了，在第%d项里",mid+1);

    while(1);
  return 0;
}
