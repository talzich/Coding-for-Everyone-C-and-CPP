#include <stdio.h>

int main(void){
    double x = 0.123456789;
    printf("General printing ideas:\n");
    printf("x is %-12.5e, and %e and %10.5f and %10d\n\n", x,x,x,x);
    return 0;
}