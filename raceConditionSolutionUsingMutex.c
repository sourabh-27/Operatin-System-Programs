#include<stdio.h>
#include<pthread.h>
#include<sys/stat.h>
pthread_mutex_t l;
int shared=1;
void fun()
{
pthread_mutex_lock(&l);
int x;
x=shared;
x++;
sleep(2);
shared=x;
pthread_mutex_unlock(&l);
}
void fun1()
{
pthread_mutex_lock(&l);
int y;
y=shared;
y--;
sleep(2);
shared=y;
pthread_mutex_unlock(&l);
}

int main()
{
pthread_mutex_init(&l,NULL);
pthread_t t1,t2;
pthread_create(&t1,NULL,fun,NULL);
pthread_create(&t2,NULL,fun1,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
printf("%d",shared);

}


