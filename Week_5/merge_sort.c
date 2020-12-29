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