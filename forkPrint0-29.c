#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main()
{ 
  pid_t p;
int i, j;
p = fork();
switch(p){
case -1: printf("error\n");
         break;
case 0: for(i  = 0; i<10; i++){
        printf("%d\n" , i);
        }
        break;
default:
        for(j = 20; j<30; j++){
        printf("%d\n", j);
        }
        break;
}}
