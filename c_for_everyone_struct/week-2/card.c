/*
	Dr. Pohl talked about this idea in the first 
	video of week 2
*/

#include <stdio.h>

typedef struct{
	int pips; // could be 1-13
	char suit; // h-hearts, s-spades, c-clubs, d-diamonds
}card;


int main(void){

	card deck[52];
	int i;

	for(i = 1; i <= 52; i++){
		deck[i-1].pips = i%13;
		if(!(i%13))
			deck[i-1].pips = 13;
		if(i <= 13)
			deck[i-1].suit = 'h';
		else if(i <= 26)
			deck[i-1].suit = 's';
		else if(i <= 39)
                        deck[i-1].suit = 'c';
		else
			deck[i-1].suit = 'd';
	}

	for(i = 0; i < 52; i++){
		printf("%d of %c\n", deck[i].pips, deck[i].suit);
	}

	return 0;

}
