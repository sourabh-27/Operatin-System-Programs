#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>

int main()
{
	int res, n;
	res = open("fifo1", O_WRONLY);
	write(res, "written", 7);
	printf("Process %d finished\n", getpid());

	//For compiling of readind and writing pipe gcc -o filename filename.c orrr ./filename
}
