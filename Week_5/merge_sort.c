#include <stdio.h>

//A simple method to print all the elements in an array
void print_array(size_t how_many, int array[]){
    int i;
    for (i = 0; i < how_many; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

//A method to merge two sorted array into a bigger sorted array
void merge(int a[], int b[], int c[], size_t a_size, size_t b_size){
    
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

//A recursive method to split an array into two subarrays
void merge_sort(int arr[], size_t length){
    //Base case
    if (length < 2) return;

    //Determining where we will split the array
    size_t mid;
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
    merge_sort(l,mid);
    merge_sort(r, length - mid);
    merge(l,r,arr, mid, length - mid);
}

int main(void){

    int a[] = {7,3,9,5,0,1,-3,12,63,77,234,11,7,12};
    size_t a_size = sizeof(a)/sizeof(int);
    printf("**********Before sort**********\n");
    print_array(a_size, a);

    merge_sort(a, a_size);
    printf("**********After sort**********\n");
    print_array(a_size, a);
    return 0;
} 