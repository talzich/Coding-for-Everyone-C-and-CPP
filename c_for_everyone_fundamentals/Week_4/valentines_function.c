#include <stdio.h>

void printVery(int count){
  if(count >= 1 && count <= 10)
  {
    printf("I love you\n");
    while(count > 0)
    {
      printf("very\n");
      count--;
    }
    printf("much\n");
  }
}

int main(void){
  int love;
  printf("How deep is your love? (1-10)\n");
  scanf("%d",& love);
  printVery(love);
  return 0;
}
