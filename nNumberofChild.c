#include<stdio.h>
int main()
{
for(int i=0;i<5;i++) // loop will run n times (n=5) you can give any value of n you will jsut have to //chang the values in for loop
{
if(fork() == 0)
{
printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid());
exit(0);
}
}
for(int i=0;i<5;i++) // loop will run n times (n=5)// change the value here too if you are changing above
wait(NULL);
}
