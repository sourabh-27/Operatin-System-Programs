#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
pid_t p;
p=fork();
if(p<0)
{
printf("error\n");
}
else if(p==0)
{
printf("the child id is%d\n",getpid());
}
else
{
printf("the grandfather  id is%d\n",getppid());
printf("the father id is%d\n",getpid());
}
}
