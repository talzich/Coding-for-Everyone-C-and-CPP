#include <stdio.h>
#include <stdlib.h>

int main(void){

    int arr[] = {1,2,3,4,5};
    int len = sizeof(arr)/sizeof(int);
    for (int i = 0; i < len; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    return 0;
}