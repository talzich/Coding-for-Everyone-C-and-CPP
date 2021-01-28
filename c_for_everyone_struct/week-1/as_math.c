/*
	Uses asserts within a trivial program
*/

#include <assert.h>
#include <stdio.h>

int main(void){
	
	double x, y;
	while(1){
		printf("Read in 2 floats:\n");
		scanf("%lf %lf", &x, &y);
		assert(y != 0);
		printf("x/y = %lf\n", x/y);
	}
	return 0;
}

