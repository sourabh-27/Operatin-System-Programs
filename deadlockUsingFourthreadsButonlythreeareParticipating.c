#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int shared = 1;
pthread_mutex_t l,l1,l2,l3;
void fun4(){
    printf("thread 4 is complete and thsu is not in deadlock");
        }
void *fun1()
{
	int x;
	pthread_mutex_lock(&l);
        	
	x = shared;
	x++;
	sleep(1);
        pthread_mutex_lock(&l1);
        pthread_mutex_lock(&l3);
	shared = x;
               pthread_mutex_unlock(&l3);
	pthread_mutex_unlock(&l1);
	pthread_mutex_unlock(&l);
        printf("the process 1 is completed");
}
	
void *fun2()
{
	int y;
        	pthread_mutex_lock(&l1);
	
	y = shared;
 	y--;
	sleep(1);
pthread_mutex_lock(&l);
pthread_mutex_lock(&l3);
	shared = y;
              pthread_mutex_unlock(&l3);
	pthread_mutex_unlock(&l);
        	pthread_mutex_unlock(&l1);
          printf("the process 2 is completed");
}
void *fun3(){
       int z;
       pthread_mutex_lock(&l3);
       z= shared;
       z = z+2;
       sleep(1);
       pthread_mutex_lock(&l1);
       pthread_mutex_lock(&l);
       shared = z;
       pthread_mutex_unlock(&l);
              pthread_mutex_unlock(&l1);       
pthread_mutex_unlock(&l3);
               printf("the process 3 is completed");

}

    

int main()
{
	pthread_mutex_init(&l, NULL); /*initiliazing mutex*/
        pthread_mutex_init(&l1, NULL); /*initiliazing mutex*/
        pthread_mutex_init(&l2, NULL);
      pthread_mutex_init(&l3, NULL);fun4();
	pthread_t thread1, thread2,thread3,thread4;
        pthread_create(&thread4, NULL, fun4, NULL);
        pthread_join(thread4, NULL);
	pthread_create(&thread1, NULL, fun1, NULL);
	pthread_create(&thread2, NULL, fun2, NULL);
        pthread_create(&thread3, NULL, fun3, NULL);
        pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
        pthread_join(thread3,NULL);
        
	printf("FInal vvalue of shared is %d \n", shared);
}




