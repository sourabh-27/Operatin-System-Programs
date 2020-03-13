#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int shared = 1;
void *fun1()
{
	int x;
	x = shared;
	x = x++;
	sleep(4);
	shared = x;
}
	
void *fun2()
{
	int y;
	y = shared;
 	y = y++;
	sleep(3);
	shared = y;
}
int main()
{
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, fun1, NULL);
	pthread_create(&thread2, NULL, fun2, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("FInal vvalue of shared is %d \n", shared);
}




