#include<stdio.h>
#define PI 3.14159

int main(void){
 double radius;
 printf(“Enter radius:\n”);
 scanf(“%lf”, &radius);
 printf(“volume is : %lf \n“  , (4*PI*radius*radius*radius)/3.0 );
 return 0;
}
