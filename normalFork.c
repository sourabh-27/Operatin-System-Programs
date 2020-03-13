#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
pid_t p;
p=fork();
if(p<0)
{
printf("error");
}
else if(p==0)
{
printf("the child id is%d",getpid());
}
else
{
printf("the father id is%d",getpid());
}}
