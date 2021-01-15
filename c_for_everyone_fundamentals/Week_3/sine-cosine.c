#include <stdio.h>
#include <math.h>

int main(void){
    /*
      We will increment this variable by 0.1 until it reaches 1.
      For each increment we will sine and cosine this value;
    */
    double i = 0.1;

    /*
      We will assign the value of sine and cosine of i to these variables and
      print them
    */
    double sineVal = 0, cosineVal =0;

    while ((1-i) > 0.1) {
      sineVal = sin(i);
      cosineVal = cos(i);
      printf("sine of %lf is: %lf\t cosine of %lf is: %lf\n", i, sineVal, i, cosineVal);
      i = i + 0.1;
    }

    return 0;
}
