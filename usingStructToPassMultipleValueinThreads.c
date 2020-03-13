#include<stdio.h>
#include<pthread.h>
struct s{
  int arg1;
  int arg2;
};
void fun(void *arguments){
  struct s *args = arguments;
  printf("%d\n", args -> arg1 + args -> arg2);
  }
void fun1(){
  printf("welcome to hell");
}
int main(){
   pthread_t t, t1;
   struct s args;
   args.arg1 = 1;
   args.arg2 = 2;
   pthread_create(&t,NULL,fun,&args);
   pthread_create(&t1,NULL,fun1,NULL);
   pthread_join(t,NULL);
   pthread_join(t,NULL);
   }
