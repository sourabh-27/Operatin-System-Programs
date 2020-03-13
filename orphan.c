#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
                pid_t  p;
                p =fork(); // creates duplicate process P1
                if (p > 0)
{
sleep(3);
printf("in parent %d \n",getpid());
}
else if (p==0)
{
sleep(5);
printf("My id is %d \n", getpid());
printf("My parent is %d \n", getppid());
system("ps -eo pid,ppid,stat,cmd");// this command opens the process table
}
}
