/**
 * n皇后问题解决
 * @author lin
 *
 */

#include <iostream>
#include <cmath>
#include<time.h>

using namespace std;
/**皇后的数目*/
static int num;
/**下标i表示第几行，x[i]表示第i行皇后的位置,注意此处0行不用*/
static int *x;
/**解的数目*/
static int sum = 0;


/**
 * 判断第k行皇后可以放置的位置
 * @param k k表示第k行，X[K]k表示第k行上皇后的位置
 * @return boolean false表示此处不能放置皇后
 */
bool place( int k )
{
    for ( int j = 1; j < k; j++ )
    {
        /* 如果当前传入的第K行上的皇后放置的位置和其它皇后一个对角线(abs(x[k]- x[j])==abs(k-j)或一个直线上(x[j] == x[k]) */
        if ( abs( x[k] - x[j] ) == abs( k - j ) || x[j] == x[k] )
        {
            return(false);
        }
    }
    return(true);
}


/**
 * 一行一行的确定该行的皇后位置
 * @param t
 */
void backtrack( int t )
{
    if ( t > num )                  /* 如果当前行大于皇后数目，表示找到解了 */
    {
        sum++;
        /* 依次打印本次解皇后的位置 */
        for ( int m = 1; m <= num; m++ )
        {
            //cout << x[m];   /* 这一行用输出当递归到叶节点的时候，一个可行解 */
            //这里只是为了好看才写成下面的
            for(int k =1; k <= num;k++){
                if(k == x[m]){
                    cout << x[m] <<" ";
                }else {
                    cout << "* ";//用*表示没有被用到的位置
                }
            }
            cout << endl;

        }
        cout << endl;
    } else {
        for ( int i = 1; i <= num; i++ )
        {
            x[t] = i;       /* 第t行上皇放在i列处 */
            if ( place( t ) )
            {
                /* 此处的place函数用来进行我们上面所说的条件的判断，如果成立，进入下一级递归 */
                backtrack( t + 1 );
            }
        }
    }
}


int main()
{
    cout<<"请输入皇后数目：";
    cin>>num;

    clock_t start,finish;
    double totaltime;//计算程序运行时间
    start=clock();//起始时间

    x   = new int[num + 1];     /* 此处注意加1，这里0行不用，1-num分别对应1-num行 */
    for ( int i = 0; i <= num; i++ )
        x[i] = 0;
    backtrack( 1 );                 /*传入第一个皇后，开始递归 */
    cout << "方案共有" << sum;
    delete[]x;

    finish=clock();//结束时间
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<"\n此程序的运行时间为"<<totaltime<<"秒！"<<endl;

    while (1);
    return(0);
}
