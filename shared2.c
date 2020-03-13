//Program 2: This program attaches itself to the shared memory segment created in Program 1 and then //reads whatever was written in the shared memory via Program 1

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/shm.h>
int main()
{
    int i;
    void *shared_memory;
    char buff[100];
    int shmid;
    shmid=shmget((key_t)2345, 1000,0666);
    printf("Key of shared memory is %d\n",shmid);
    shared_memory=shmat(shmid,NULL,0); //process attached to shared memory segment
    printf("Process attached at %X\n",(int)shared_memory);
    printf("Data read from shared memory is : %s\n",shared_memory);
}
