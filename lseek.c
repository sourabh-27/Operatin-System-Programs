#include<stdio.h>
#include<sys/stat.h>
#include<pthread.h>
#include<fcntl.h>
int main()
{
int fd;
char buf[40];
fd=open("m.txt",O_RDWR,0777);
read(fd,buf,5);
write(1,buf,5);
printf("\n");
int off;
off=lseek(fd,2,SEEK_CUR);
read(fd,buf,5);
write(1,buf,5);
printf("\n");
off=lseek(fd,2,SEEK_SET);
read(fd,buf,5);
write(1,buf,5);
printf("\n");
off=lseek(fd,10,SEEK_END);
read(fd,buf,5);
write(1,buf,5);
printf("\n");
}

