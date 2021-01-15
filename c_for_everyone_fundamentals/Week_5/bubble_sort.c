#include <stdio.h>

//A swap method using only pointers as parameters
void swap(int *p1, int *p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

//A simple method to print all the elements in an array
void print_array(int how_many, int array[]){
    int i;
    for (i = 0; i < how_many; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

//Bubble sort algorithm implementation
void bubble(int how_many, int array[]){
    int i, j; 
    int go_on;

    for (i = 0; i < how_many; i++)
    {
        for(j = how_many - 1; j > i; j--){
            if(array[j-1] > array[j])
                swap(&array[j-1], &array[j]);
        }
    }
    
}

int main(void){
    int array[] = {78, 67, 92, 88, 82};
    print_array(5, array);
    bubble(5, array);
    print_array(5, array);
}