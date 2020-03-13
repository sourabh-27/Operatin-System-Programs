#include<stdio.h>
#include<sys/stat.h>
#include<pthread.h>
#include<fcntl.h>
void fun(char buf[40])
{
int fd;
fd=open("m.txt",O_CREAT|O_RDWR,0777);
write(fd,buf,40);
}
int main()
{
char buf[40];
int n;
read(0,buf,40);
write(1,buf,40);
pthread_t p;
pthread_create(&p,NULL,fun,buf);
pthread_join(p,NULL);
}
