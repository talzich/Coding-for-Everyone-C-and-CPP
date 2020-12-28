#include <stdio.h>

//A simple method to calculate the average grade
double avg_grades(int how_many, int grades[]){
    int i;
    double sum = 0.0;
    for (i = 0; i < how_many; i++)
    {
        sum += grades[i];
    }
    return (sum/how_many);
}

//A simple method to print all the grades
void print_grades(int how_many, int grades[]){
    int i;
    printf("There are %d grades in this class and they are:\n\n", how_many);
    for (i = 0; i < how_many; i++)
    {
        printf("%d\n", grades[i]);
    }
}

int main(void){
    const int SIZE = 5;
    int grades[SIZE] = {78,67,92,83,88 };

    print_grades(SIZE, grades);
    printf("\n\n");
    printf("Average grade in this class is %0.1f\n", avg_grades(SIZE, grades));
}