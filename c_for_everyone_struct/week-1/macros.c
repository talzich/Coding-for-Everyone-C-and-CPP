/*
    Use of macros
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_W 8800
#define MIN_W 4400

// Produce a macro which generates a random weight within the range

#define RANGE 4400
#define POPULATION 1000
#define WEIGHT_OVER rand()%RANGE
#define WEIGHT WEIGHT_OVER + MIN_W
#define FILL for(i = 0; i < POPULATION; i++)\
                data[i] = WEIGHT

void print(int d[], int size){
    int i;
    for(i = 0; i < size; i++){
        printf("%d\t", d[i]);
        if((i+1)%10 == 0) printf("\n");

    }
}

int main(void){
    int i; 
    int data[POPULATION];
    srand(time(0));
    FILL;
    print(data, POPULATION);
    printf("\n\n");
    return 0;
}