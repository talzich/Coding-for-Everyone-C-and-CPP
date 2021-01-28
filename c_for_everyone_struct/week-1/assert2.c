/*
	Assert2.c from week 1
	Uses asserts within a trivial program
*/

#define NDEBUG //goes before <assert.h>
#include <assert.h>
#include <stdio.h>
#include <ctype.h>

int main(void){
	assert(0);
	printf("My Program Is Running\n");
	return 0;
}

