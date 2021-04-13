#include <stdio.h>

double sum_array(double *arr, size_t size){
    int i;
    double sum = 0.0;
    for(i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum;
}

int main(void){

    double arr[] = {0.5, 2.0, 3.8};
    printf("Sum of array %lf\n", sum_array(arr, 3));
    return 0;
}