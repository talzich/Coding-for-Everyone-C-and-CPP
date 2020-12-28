#include <stdio.h>
#include <stdlib.h>

int main(void){

    //Declaring  a new array
    int arr[] = {1,2,3,4,5};

    //Length of the array is the number of bytes this array takes up divided by the number of
    //bytes it takes to represent an int
    int len = sizeof(arr)/sizeof(int);
    
    for (int i = 0; i < len; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    //Declaring an array of 5 cells, all but the first cell store 0 
    int array[5] = {1};
    for (int i = 0; i < len; i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }

    //Declaring an array of chars (A String)
    char str[] = "ABC";

    //Using the sentinel character ('\0') to know when to break out of the loop
    for(int i = 0; str[i] != '\0'; i++)
    {
        printf("str[%d] = %c\n", i, str[i]);
    }

    return 0;
}