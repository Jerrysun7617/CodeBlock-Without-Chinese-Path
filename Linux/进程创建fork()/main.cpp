#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//#includ <fork.h>

int main()
{
  int pid;        //���̱�ʶ��
  pid = fork();     //����һ���µĽ���
  if(pid<0)
    {
    printf("��������ʧ��!");
    exit(1);
    }
  else if(pid==0)   //���pidΪ0���ʾ��ǰִ�е����ӽ���
    printf("�����ӽ���,���̱�ʶ����%d\n",getpid());
  else          //����Ϊ������
    printf("���Ǹ�����,���̱�ʶ����%d\n",getpid());
  return 0;
}
