#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
int main(){
 int res;
 res = mkfifo("fifo1", 0777);//creates a pipe named fifo1
 printf("named pipe created");
 }
