#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
void *fun(int n){
 for(int i = 0; i<=n; i++)
   printf("%d\n", i);
 }
int main(){
 int m  = 5;
 pthread_t t;
 void *result;
 pthread_create(&t,NULL,fun,m);
 pthread_join(t,&result);
 for(int i = 20; i<=24; i++)
   printf("%d\n", i);
}
