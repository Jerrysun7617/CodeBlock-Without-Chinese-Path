#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//#includ <fork.h>

int main()
{
  int pid;        //进程标识符
  pid = fork();     //创建一个新的进程
  if(pid<0)
    {
    printf("创建进程失败!");
    exit(1);
    }
  else if(pid==0)   //如果pid为0则表示当前执行的是子进程
    printf("这是子进程,进程标识符是%d\n",getpid());
  else          //否则为父进程
    printf("这是父进程,进程标识符是%d\n",getpid());
  return 0;
}
