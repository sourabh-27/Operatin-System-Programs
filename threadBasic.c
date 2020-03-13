

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> //Header file for sleep().
#include<pthread.h>
// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *myThreadFun(void *vargp)
{
sleep(1);
printf("Printing Quiz from Thread \n");
return NULL;
}
int main()
{
pthread_t thread_id;
printf("Before Thread\n");
pthread_create(&thread_id, NULL, myThreadFun, NULL);
pthread_join(thread_id, NULL);
printf("After Thread\n");
exit(0);
}
/*In main() we declare a variable called thread_id, which is of type pthread_t, which is an
integer used to identify the thread in the system. After declaring thread_id, we call
pthread_create() function to create a thread.
pthread_create() takes 4 arguments.
The first argument is a pointer to thread_id which is set by this function.
The second argument specifies attributes. If the value is NULL, then default attributes
shall be used.
The third argument is name of function to be executed for the thread to be created.
The fourth argument is used to pass arguments to the function, myThreadFun.
The pthread_join() function for threads is the equivalent of wait() for processes. A call to
pthread_join blocks the calling thread until the thread with identifier equal to the first
argument terminates.*/
