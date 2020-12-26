#include <stdio.h>

extern int reps = 0;

void f(void){
    static int called = 0;
    printf("f called %d\n", called);
    called++;
    reps += called;
}

int main(void){

    

    return 0;
}