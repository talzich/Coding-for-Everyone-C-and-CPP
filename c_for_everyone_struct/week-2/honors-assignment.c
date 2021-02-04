#include <stdio.h>
#include <stdlib.h>

#define KING 13
#define DECK_SIZE 52

// Cards suits
typedef enum
{
    spades,
    hearts,
    clubs,
    diamonds
} suit;

typedef struct
{
    short pips; // could be 1-13
    suit s;     // from
} card;

// This method gets a deck of cards and shuffles it
int shuffle(card deck[], int len)
{

    // We want a standard poker deck so we need 52 cards
    if (len != DECK_SIZE)
    {
        printf("Wrong deck size\n");
        return -1;
    }

    int i;
    for (i = 0; i < len - 1; i++)
    {
        // Getting another index from 0 to len-1
        int j = i + rand() / (RAND_MAX / (len - i) + 1); 

        // Shuffling 
        card t = deck[j];
        deck[j] = deck[i];
        deck[i] = t;
    }
    return 0;
}

// This method fills the deck with standard poker cards
int init(card deck[], int len)
{
    short i;

    // We want a standard poker deck so we need 52 cards
    if (len != DECK_SIZE)
    {
        printf("Wrong deck size\n");
        return -1;
    }
    for (i = 1; i <= len; i++)
    {
        // Fill the cards with 1-13
        deck[i - 1].pips = i % 13;
        if (!(i % 13))
            // If i%13 == 0, this card is a king
            deck[i - 1].pips = KING;
        if (i <= 13)
            deck[i - 1].s = spades;
        else if (i <= 26)
            deck[i - 1].s = hearts;
        else if (i <= 39)
            deck[i - 1].s = clubs;
        else
            deck[i - 1].s = diamonds;
    }
    return 0;
}


// This function prints the deck according to its current order
int print_deck(card deck[], int len){
    
    if(len != DECK_SIZE){
        printf("Wrong deck size\n");
        return -1;
    }

    int i;
    for(i = 0; i < DECK_SIZE; i++){
		switch (deck[i].s)
        {
        case spades:
            printf("%d of spades\n", deck[i].pips);
            break;
        
        case hearts:
            printf("%d of hearts\n", deck[i].pips);
            break;

        case clubs:
            printf("%d of clubs\n", deck[i].pips);
            break;

        case diamonds:
            printf("%d of diamonds\n", deck[i].pips);
            break;
	    }
    }
    return 0;
}


int main(void){

    card deck[52];
    init(deck, DECK_SIZE);
    print_deck(deck, DECK_SIZE);
    shuffle(deck, DECK_SIZE);
    print_deck(deck, DECK_SIZE);
    return 0;
}



