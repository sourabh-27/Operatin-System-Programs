#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int shared = 1;
pthread_mutex_t l,l1;
void *fun1();
void *fun2();
void *fun3();
int main()
{     
	pthread_mutex_init(&l, NULL); /*initiliazing mutex*/
        pthread_mutex_init(&l1, NULL); /*initiliazing mutex*/
	pthread_t thread1, thread2,thread3;
	pthread_create(&thread1, NULL, fun1, NULL);
	pthread_create(&thread2, NULL, fun2, NULL);
        pthread_create(&thread3,NULL,fun3,NULL);
         pthread_join(thread3,NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("FInal vvalue of shared is %d \n", shared);
}
void *fun1()
{        printf("i am here");
	int x;
	pthread_mutex_lock(&l);
        	
	x = shared;
	x++;
	sleep(1);
        pthread_mutex_lock(&l1);
	shared = x;
        	pthread_mutex_lock(&l1);
	pthread_mutex_unlock(&l);
}
	
void *fun2()
{       printf("yo");
	int y;
	pthread_mutex_lock(&l1);
       
	y = shared;
 	y--;
	sleep(3);
        pthread_mutex_lock(&l);
	shared = y;
	pthread_mutex_unlock(&l);
        	pthread_mutex_unlock(&l1);
}
void *fun3(){
     
     printf("done thread3");
sleep(1);}

