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
	int res;
	res = mkfifo("fifo1", 0777); //This is to create the file and giving permissions
	printf("named pipe created\n");
}
