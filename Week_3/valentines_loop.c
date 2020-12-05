#include <stdio.h>

int main(void){
  int love;
  printf("How deep is your love? (1-10)\n");
  scanf("%d\n", love);
  if(love >= 1 && love <= 10)
  {
    printf("I love you very\n");
    while(love > 0)
    {
      printf("very\n");
      love--;
    }
    printf("much\n");
  }
}
