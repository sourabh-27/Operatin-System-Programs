#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
         pid_t  p;
                p=fork(); // creates duplicate process P1
                if (p > 0)
{
	sleep(5);
	printf("My id is %d\n",getpid());
}
else 
{	
sleep(3);	 
printf("My id is %d\n",getpid());
	printf("My parent id id%d\n", getppid());
	exit(0);
}
system("ps -eo pid,ppid,stat,cmd");// this is used to open the process table
return 0;
}

