#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <time.h>

#define TEST_DATA_LENGTH 100000 //ÿ���̲߳�������
#define THREAD_NUM 10 //�̸߳���

using namespace std;//����std�����ռ�

mutex m;//����������m

long n_total = 0;
long m_total = 0;
atomic <long> a_total;//ԭ�����ĳ�ʼ��

//�ڲ����û�������ԭ����������
void test_f_normal()
{
    for(int i = 0; i < TEST_DATA_LENGTH; i++)
    {
        n_total += 1;
    }
}

//ʹ��mutex������
void test_f_mutex()
{
    for(int i = 0; i < TEST_DATA_LENGTH; i++)
    {
        m.lock();
        m_total += 1;
        m.unlock();
    }
}
//ʹ��ԭ�Ӳ���
void test_f_atomic()
{
    for(int i = 0; i < TEST_DATA_LENGTH; i++)
    {
        a_total += 1;
    }
}




int main()
{
    thread ts[THREAD_NUM];
    //normal mode ,result is error
    clock_t start = clock();

    for(int i = 0; i < THREAD_NUM; i++)
    {
        ts[i] = thread(&test_f_normal);
    }

    for(int i = 0; i < THREAD_NUM; i++)
    {
        ts[i].join();
    }

    clock_t end = clock();
    cout << "total: " << n_total << endl;
    cout << "test_f_normal: " << end - start << endl;


    //use mutex ,
    clock_t mstart = clock();

    for(int i = 0; i < THREAD_NUM; i++)
    {
        ts[i] = thread(&test_f_mutex);
    }

    for(int i = 0; i < THREAD_NUM; i++)
    {
        ts[i].join();
    }

    clock_t mend = clock();
    cout << "total: " << m_total << endl;
    cout << "test_f_mutex: " << mend - mstart << endl;

    //use atomic
    clock_t astart = clock();

    for(int i = 0; i < THREAD_NUM; i++)
    {
        ts[i] = thread(&test_f_atomic);
    }

    for(int i = 0; i < THREAD_NUM; i++)
    {
        ts[i].join();
    }

    clock_t aend = clock();
    cout << "total: " << a_total << endl;
    cout << "test_f_atomic: " << aend - astart << endl;

    system("pause");
    return 0;
}