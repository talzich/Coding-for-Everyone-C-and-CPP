#include <stdio.h>

//A swap method using only pointers as parameters
void swap(int *p1, int *p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}


int main(void){
    int a = 1; 
    int b = 2;

    printf("******Before swap******\n a = %d\tb = %d\n", a, b);
    swap(&a, &b);//Passing addresses as parameter
    printf("******After swap******\n a = %d\tb = %d\n", a, b);

}