#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define DECK_SIZE 52
#define HAND_SIZE 7

#define ACE 1
#define KING 13
#define QUEEN 13
#define JACK 13

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
// It ensures that the array will be shuffled based on a random seed taken from the usec time.
// Found that great array shuffler at https://stackoverflow.com/questions/6127503/shuffle-array-in-c
int shuffle(card deck[], int len)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    int usec = tv.tv_usec;
    srand48(usec);


    if (len > 1) {
        size_t i;
        for (i = len - 1; i > 0; i--) {
            size_t j = (unsigned int)(drand48()*(i+1));
            card t = deck[j];
            deck[j] = deck[i];
            deck[i] = t;
        }
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
int print_cards(card deck[], int len){
    
    int i;
    for(i = 0; i < len; i++){
		switch (deck[i].s)
        {
        case spades:
            int pip = deck[i].pips;
            switch (pip)
            {
            case ACE:
                printf("Ace of Spades\n");
                break;

            case KING:
                printf("King of Spades\n");
                break;

            case QUEEN:
                printf("Queen of Spades\n");
                break;

            case JACK:
                printf("Jack of Spades\n");
                break;
            default:
                printf("%d of Spades\n", deck[i].pips);
                break;
            }
        
        case hearts:
            int pip = deck[i].pips;
            switch (pip)
            {
            case ACE:
                printf("Ace of Hearts\n");
                break;

            case KING:
                printf("King of Hearts\n");
                break;

            case QUEEN:
                printf("Queen of Hearts\n");
                break;

            case JACK:
                printf("Jack of Hearts\n");
                break;
            default:
                printf("%d of Hearts\n", deck[i].pips);
                break;
            }

        case clubs:
            int pip = deck[i].pips;
            switch (pip)
            {
            case ACE:
                printf("Ace of Clubs\n");
                break;

            case KING:
                printf("King of Clubs\n");
                break;

            case QUEEN:
                printf("Queen of Clubs\n");
                break;

            case JACK:
                printf("Jack of Clubs\n");
                break;
            default:
                printf("%d of Clubs\n", deck[i].pips);
                break;
            }

        case diamonds:
            int pip = deck[i].pips;
            switch (pip)
            {
            case ACE:
                printf("Ace of Diamonds\n");
                break;

            case KING:
                printf("King of Diamonds\n");
                break;

            case QUEEN:
                printf("Queen of Diamonds\n");
                break;

            case JACK:
                printf("Jack of Diamonds\n");
                break;
            default:
                printf("%d of Diamonds\n", deck[i].pips);
                break;
            }
	    }
    }
    return 0;
}

// This function gets a card deck and deals a hand of desired size
card *deal_hand(int hand_size, card deck[]){

    if(hand_size > DECK_SIZE){
        printf("Invalid hand size requested\n");
        return NULL;
    }
    // We shuffle the cards before dealing a hand
    shuffle(deck, DECK_SIZE);
    card *hand = (card *)malloc(HAND_SIZE*sizeof(card));
    
    int i;
    for(i = 0; i<hand_size; i++){
        hand[i] = deck[i];
    }
    return hand;
}

// This function checks to see whether a hand has an ace in it
int is_ace_high(card hand[], int hand_size){
    int i;
    for(i = 0; i<hand_size; i++){
        if(hand[i].pips == 1) return 1;
    }
    return 0;
}

// This function checks to see whether a hand has a pair in it
int is_pair(card hand[], int hand_size){

    int pips[13] = {0};
    int i;
    for(i = 0; i<hand_size; i++){
        pips[hand[i].pips]++;
        if(pips[hand[i].pips] == 2) return 1;
    }
    return 0;
}

int is_two_pair(card hand[], int hand_size){
    int count = 0;
    int pips[13] = {0};
    int i;
    for(i = 0; i<hand_size; i++){
        pips[hand[i].pips]++;
        if(pips[hand[i].pips] == 2) count++;
    }
    return (count == 2);
}
// This function checks to see whether a hand has three of a kind
int is_three(card hand[], int hand_size){

    int pips[13] = {0};
    int i;
    for(i = 0; i<hand_size; i++){
        pips[hand[i].pips]++;
        if(pips[hand[i].pips] == 3) return 1;
    }
    return 0;
}

int main(void){

    card deck[52];
    init(deck, DECK_SIZE);
    shuffle(deck, DECK_SIZE);
    card *hand = deal_hand(HAND_SIZE, deck);
    print_cards(hand, HAND_SIZE);
    printf("Three of a Kind: %d\n", is_three(hand, HAND_SIZE));
    printf("Pair: %d\n", is_pair(hand, HAND_SIZE));
    printf("Ace: %d\n", is_ace_high(hand, HAND_SIZE));
    return 0;
}



