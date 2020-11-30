#include <stdio.h>
#include <math.h>

/*
  In this program I will be using the math.h library in order to help with
  my calculation. The meath.h library contatins the sin method, which returns
  a double type value.
*/
int main(void){

  double input = 0.0; //input from user
  double res = 0.0; // we will return this variable, after assigning the right value

  //We will get the value we will operate on in the next two lines
  printf("Please enter a number betweem 0 and 1 (non-inclusive)\n");
  scanf("%lf",& res);

  //This loop will make sure the user gives us the right value to work with
  while (res <= 0 || res >= 1)
  {
    printf("Wrong assignment! Please enter a number betweem 0 and 1 (non-inclusive)\n");
    scanf("%lf",& res);
  }
  //If we got here, we know we are working with a right value
  printf("The sine of %lf is %lf\n", res, sin(res));
  return 0;
}
