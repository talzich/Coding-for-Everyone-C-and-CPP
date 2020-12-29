#include <stdio.h>

//A simple method to print all the elements in an array
void print_array(int how_many, int array[]){
    int i;
    for (i = 0; i < how_many; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

//A recursive method to split an array into two subarrays
void merge_sort(int arr[]){

    //Length of arr
    int length = sizeof(arr)/sizeof(int);
    //Base case
    if (length < 2) return;

    //Determining where we will split the array
    int mid;
    if(length%2 == 0) mid = length/2;
    else mid = (length + 1)/2;

    //Sizes of new arrays
    int l[mid];
    int r[length - mid];

    for (int i = 0; i < mid; i++)
    {
        l[i] = arr[i];
    }
    for (int j = mid; j < length; j++)
    {
        r[j - mid] = arr[j];
    }
    merge_sort(l);
    merge_sort(r);
    merge(l,r,arr, mid, length - mid);
}

//A method to merge two sorted array into a bigger sorted array
void merge(int a[], int b[], int c[], int a_size, int b_size){
    
    //Pointers
    int i, j, k; 
    i=j=k=0;

    //Merge into the current cell in c the smaller element between a and b
    while (i < a_size && j < b_size){
        if(a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    //Clean up, in case on array finished before the other one    
    while (i < a_size)
    {
        c[k++] = a[i++];
    }

    while (j < b_size)
    {
        c[k++] = b[j++];
    }
}


int main(void){

    int a[] = {7,3,9,5,0,1,-3,12,63,77,234,11,7,12};
    int a_size = sizeof(a)/sizeof(int);
    printf("**********Before sort**********");
    print_array(a, a_size);

    merge_sort(a);
    printf("**********After sort**********");
    print_array(a, a_size);
    return 0;
} 