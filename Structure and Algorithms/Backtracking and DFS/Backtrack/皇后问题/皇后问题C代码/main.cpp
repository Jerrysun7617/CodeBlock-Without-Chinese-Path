/**
 * n�ʺ�������
 * @author lin
 *
 */

#include <iostream>
#include <cmath>
#include<time.h>

using namespace std;
/**�ʺ����Ŀ*/
static int num;
/**�±�i��ʾ�ڼ��У�x[i]��ʾ��i�лʺ��λ��,ע��˴�0�в���*/
static int *x;
/**�����Ŀ*/
static int sum = 0;


/**
 * �жϵ�k�лʺ���Է��õ�λ��
 * @param k k��ʾ��k�У�X[K]k��ʾ��k���ϻʺ��λ��
 * @return boolean false��ʾ�˴����ܷ��ûʺ�
 */
bool place( int k )
{
    for ( int j = 1; j < k; j++ )
    {
        /* �����ǰ����ĵ�K���ϵĻʺ���õ�λ�ú������ʺ�һ���Խ���(abs(x[k]- x[j])==abs(k-j)��һ��ֱ����(x[j] == x[k]) */
        if ( abs( x[k] - x[j] ) == abs( k - j ) || x[j] == x[k] )
        {
            return(false);
        }
    }
    return(true);
}


/**
 * һ��һ�е�ȷ�����еĻʺ�λ��
 * @param t
 */
void backtrack( int t )
{
    if ( t > num )                  /* �����ǰ�д��ڻʺ���Ŀ����ʾ�ҵ����� */
    {
        sum++;
        /* ���δ�ӡ���ν�ʺ��λ�� */
        for ( int m = 1; m <= num; m++ )
        {
            //cout << x[m];   /* ��һ����������ݹ鵽Ҷ�ڵ��ʱ��һ�����н� */
            //����ֻ��Ϊ�˺ÿ���д�������
            for(int k =1; k <= num;k++){
                if(k == x[m]){
                    cout << x[m] <<" ";
                }else {
                    cout << "* ";//��*��ʾû�б��õ���λ��
                }
            }
            cout << endl;

        }
        cout << endl;
    } else {
        for ( int i = 1; i <= num; i++ )
        {
            x[t] = i;       /* ��t���ϻʷ���i�д� */
            if ( place( t ) )
            {
                /* �˴���place����������������������˵���������жϣ����������������һ���ݹ� */
                backtrack( t + 1 );
            }
        }
    }
}


int main()
{
    cout<<"������ʺ���Ŀ��";
    cin>>num;

    clock_t start,finish;
    double totaltime;//�����������ʱ��
    start=clock();//��ʼʱ��

    x   = new int[num + 1];     /* �˴�ע���1������0�в��ã�1-num�ֱ��Ӧ1-num�� */
    for ( int i = 0; i <= num; i++ )
        x[i] = 0;
    backtrack( 1 );                 /*�����һ���ʺ󣬿�ʼ�ݹ� */
    cout << "��������" << sum;
    delete[]x;

    finish=clock();//����ʱ��
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<"\n�˳��������ʱ��Ϊ"<<totaltime<<"�룡"<<endl;

    while (1);
    return(0);
}
