#include<stdio.h>
#include<string.h>
int main(){
char c[1];
int x;
while(x = read(0,c,1) !=0){
      //write(1,c,x);
     //printf("%s",c);
     if(strcmp(c,"q")==0||strcmp(c,"Q")==0)exit(1);
     else printf("%s",c);
}
}
