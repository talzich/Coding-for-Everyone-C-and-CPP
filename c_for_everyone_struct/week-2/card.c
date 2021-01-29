/*
	Dr. Pohl talked about this idea in the first 
	video of week 2
*/

#include <stdio.h>

#define SPADES 's'
#define HEARTS 'h'
#define DIAMONDS 'd'
#define CLUBS 'c'

#define KING 13

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
			deck[i-1].pips = KING;
		if(i <= 13)
			deck[i-1].suit = SPADES;
		else if(i <= 26)
			deck[i-1].suit = HEARTS;
		else if(i <= 39)
                        deck[i-1].suit = DIAMONDS;
		else
			deck[i-1].suit = CLUBS;
	}

	for(i = 0; i < 52; i++){
		printf("%d of %c\n", deck[i].pips, deck[i].suit);
	}

	return 0;

}
