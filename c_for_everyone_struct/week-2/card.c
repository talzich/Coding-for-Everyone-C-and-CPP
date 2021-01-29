/*
	Dr. Pohl talked about this idea in the first 
	video of week 2
*/

#include <stdio.h>

typedef struct{
	int pips; // could be 1-13
	char suit; h-hearts, s-spades, c-clubs, d-diamonds
}card;


int main(void){

	card deck[52];
	int i;

	for(i = 0; i < 13; i++){
		deck[i].pips = i+1;
		deck[i].suit = 'h';
	}
	
	for(i = 0; i < 13; i++){
                deck[i].pips = i+1;
                deck[i].suit = 's';
        }

	for(i = 0; i < 13; i++){
                deck[i].pips = i+1;
                deck[i].suit = 'c';
        }	

	for(i = 0; i < 13; i++){
                deck[i].pips = i+1;
                deck[i].suit = 'd';
        }

	for(i = 0; i < 52; i++){
		printf("%d of %c\n", deck[i].pips, deck[i].suit);
	}

	return 0;

}
