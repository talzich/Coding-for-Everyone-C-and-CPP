#include <stdio.h>


/*
  this program will tell you wether you need an umbrella or not
  */
int main(void){
  int weathter, outside;
  printf("Is it raining? 0 for no, 1 for yes\n");
  scanf("%d",&weathter );
  printf("Are you outside? 0 for no, 1 for yes\n" );
  scanf("%d",&outside );
  if(weathter && outside)
    printf("looks like you need an umbrella!\n");
  else
    printf("Looks like you don't need an umbrella!\n");



}
