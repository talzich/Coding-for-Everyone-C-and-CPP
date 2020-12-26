#include <stdio.h>

extern int reps = 0;

void f(void){
    static int called = 1;
    int local = 123;
    printf("f called %d, local var = %d\n", called, local);
    called++;
    reps += called;
    local++;
}

int main(void){


    auto int i = 1;
    const int Limit = 10;
    for (i = 1; i < Limit; i++)
    {
        printf("i local = %d, reps global = %d\n", i, reps);
        f();
    }
    return 0;
}