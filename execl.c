#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    printf("Before execl\n");
    execl("/bin/ps","ps",NULL);
    printf("After execlp\n");
}
// you can do "info execl" to check about the viva in cmd
// btw this is called an overlay and it is used to replace current executable process by another
// you can help of cmd by using this info command only
// you can use any of execl, execlp, execle, execvp, you just have to change the function name
