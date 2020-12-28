#include <stdio.h>

int main(void){

    /*
        Let's assume data[0] - base address - is 7006.
        In that case data[2] address is going to be 7014. 
        The calculation is (Base address + (Index in the array * sizeof(data_type)) => 7006 + 2*4 = 7014)
    */
    int data[4] = {2,4,6,8};
    int *p = &data[0];
    printf("data[0] = %d,\n", *p);
    printf("p = %p,\n", p);

    int *p1;
    //The calculation has to be done using lu because a normal pointer is represented with a hexadecimal number
    long unsigned ptr = (long unsigned)(p) + (2*sizeof(int));
    p1 = (int *)ptr;
    
    printf("data[0] = %d, data[2] = %d\n", *p, *p1);
    printf("p = %p, p1 = %p\n", p, p1);
    return 0;
}