/*  Enumerated Types
    Tal Zichlinsky
    Jen 15th, 2021
*/

#include <stdio.h>

enum day {sun, mon, tue, wed, thu, fri, sat};

void print_day(enum day d){
    switch (d)
    {
    case sun:printf("It's sunday, take a break"); break;
    case mon:printf("It's sunday, take a break"); break;
    case tue:printf("It's sunday, take a break"); break;
    case wed:printf("It's sunday, take a break"); break;
    case thu:printf("It's sunday, take a break"); break;
    case fri:printf("It's sunday, take a break"); break;
    case sat:printf("It's sunday, take a break"); break;
    
    default:
        printf("%d is an error", d);
    }
}