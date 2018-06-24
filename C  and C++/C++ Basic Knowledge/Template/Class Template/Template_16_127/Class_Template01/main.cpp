// leimoban.cpp : Defines the entry point for the console application.
//

#include<iostream>
using namespace std;
template <class MM>			//ģ��
class Array
{
private:
	MM *set;				//��ģ�嶨��ָ��
	int n;
public:
	Array(MM *data,int i);		//��ģ�����β���
	~Array(){}
	void sort();
	int seek(MM key);
	MM sum(); 				//��ģ�����η���ֵ
	void show();
};
template <class MM>			//ģ��
Array<MM>::Array(MM *data,int i)
{
	set=data;
	n=i;
}
//����
template<class MM>
void Array<MM>::sort()
{
	int i,j;
	MM temp;
	for(i=1;i<n;i++)			//����Ƚϣ��������ƣ�ÿһ�ֶ�ѡ��һ����С��
	{
		for(j=n-1;j>=i;j--)
		{
			if(set[j-1]>set[j])		//���ϴ�������
			{
				//����
				temp=set[j-1];
				set[j-1]=set[j];
				set[j]=temp;
			}
		}
	}
}
//����
template <class MM>
int Array<MM>::seek(MM key)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(set[i]==key)
		{
			return i;
		}
	}
	return -1;
}
//�������
template<class MM>
MM Array<MM>::sum()
{
	MM s=0;
	int i;
	for(i=0;i<n;i++)
	{
		s+=set[i];
	}
	return s;
}
//��ʾ����
template<class MM>
void Array<MM>::show()
{
	int i;
	for(i=0;i<n;i++)
	{
		cout<<set[i]<<" ";
	}
	cout<<endl;
}
int  main()
{
	int x[10]={70,9,25,33,83,29,60,58,47,14};
	float y[5]={7.4,2.5,8.3,5.2,0.5};
	Array<int> array1(x,10);				//����
	Array<float> array2(y,5); 				//������
	cout<<" array1[10]:"<<endl;
	cout<<" ԭ����:"; array1.show();
	cout<<" ����83�������е�λ�ã�"<<array1.seek(83)<<endl;		//����
	array1.sort();											//����
	cout<<" �����";
	array1.show();
	cout<<" array2[5]:"<<endl;
	cout<<" ԭ����:";
	array2.show();
	cout<<" ����5.2�������λ�ã�"<<array2.seek(5.8)<<endl;		//����
	array2.sort();											//����
	cout<<" �����:"; array2.show();

	while(1);
	return 0;
}


