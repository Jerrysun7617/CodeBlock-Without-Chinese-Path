#include<iostream>
#define N 10
using namespace std;
int main()
{
     int a[N],front,end,mid,x,i;
     cout<<"���������ź����a����Ԫ��:"<<endl;
     for(i=0;i<N;i++)
              cin>>a[i];
     cout<<"����������ҵ���x:"<<endl;
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
          printf("û�ҵ���\n");
     else
          printf("�ҵ��ˣ��ڵ�%d����",mid+1);

    while(1);
  return 0;
}
