// leimoban.cpp : Defines the entry point for the console application.
//

#include<iostream>
using namespace std;
template <class MM>			//模板
class Array
{
private:
	MM *set;				//用模板定义指针
	int n;
public:
	Array(MM *data,int i);		//用模板修饰参数
	~Array(){}
	void sort();
	int seek(MM key);
	MM sum(); 				//用模板修饰返回值
	void show();
};
template <class MM>			//模板
Array<MM>::Array(MM *data,int i)
{
	set=data;
	n=i;
}
//排序
template<class MM>
void Array<MM>::sort()
{
	int i,j;
	MM temp;
	for(i=1;i<n;i++)			//逐个比较，大数后移，每一轮都选出一个最小数
	{
		for(j=n-1;j>=i;j--)
		{
			if(set[j-1]>set[j])		//将较大数后移
			{
				//交换
				temp=set[j-1];
				set[j-1]=set[j];
				set[j]=temp;
			}
		}
	}
}
//查找
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
//数组求和
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
//显示数组
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
	Array<int> array1(x,10);				//整型
	Array<float> array2(y,5); 				//浮点型
	cout<<" array1[10]:"<<endl;
	cout<<" 原序列:"; array1.show();
	cout<<" 其中83在数组中的位置："<<array1.seek(83)<<endl;		//查找
	array1.sort();											//排序
	cout<<" 排序后：";
	array1.show();
	cout<<" array2[5]:"<<endl;
	cout<<" 原序列:";
	array2.show();
	cout<<" 其中5.2在数组的位置："<<array2.seek(5.8)<<endl;		//查找
	array2.sort();											//排序
	cout<<" 排序后:"; array2.show();

	while(1);
	return 0;
}


