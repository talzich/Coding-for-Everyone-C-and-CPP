/*  Enumerated Types
    Tal Zichlinsky
    Jen 15th, 2021
*/

#include <stdio.h>
#include <math.h>

enum day {sun, mon, tue, wed, thu, fri, sat};

int mod(int a, int b){
    int r = a%b;
    return r<0 ? r+b : r;
}

void print_day(enum day d){
    switch (d){
    case sun:printf("It's sunday, take a break\n"); break;
    case mon:printf("It's monday, have a great week!\n"); break;
    case tue:printf("It's tuesday, keep up the good work\n"); break;
    case wed:printf("WOOOO We're half way there! It's wednesday!\n"); break;
    case thu:printf("Thursday is here!!"); break;
    case fri:printf("Hope y'all casual AF, It's Friday"); break;
    case sat:printf("SATURDAY!! Kick back and relax!"); break;
    default:printf("%d is an error", d);
    }
}

void print_yesterday(enum day today){
    double yesterday = mod(today-1, 7);
    print_day(yesterday);
}

int main(void){

    enum day d = sun;
    print_yesterday(d);
    return 0;

}