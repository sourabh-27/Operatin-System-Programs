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
	char buffer[100];
	res = open("fifo1", O_RDONLY);
	n = read(res, buffer, 100);
	printf("Total bytes read : %d\n", n);
	printf("%s was passed to me\n", buffer);
	printf("Process %d finished\n", getpid());

	//For running, you have to run both the programs sat the same time
	//To run the program we have special method
	// Run:->       ./prog1 & ./prog2
}
