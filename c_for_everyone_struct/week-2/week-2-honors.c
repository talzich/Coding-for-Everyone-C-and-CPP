#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define DECK_SIZE 52
#define HAND_SIZE 7
#define PIPS 13

#define KING 13
#define QUEEN 12
#define JACK 11
#define ACE 1

// Cards suits
typedef enum { spades, hearts, clubs, diamonds} suit;

// This struct defines a card in a standard poler deck
typedef struct
{
    short pips; // could be 1-13
    suit suit; // taken from above enum
} card;

// This method gets a deck of cards and shuffles it
// It ensures that the deck will be shuffled based on a random seed taken from the usec time.
// Found that great array shuffler at https://stackoverflow.com/questions/6127503/shuffle-array-in-c
int shuffle(card deck[])
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    int usec = tv.tv_usec;
    srand48(usec);

    int i;
    for (i = DECK_SIZE - 1; i > 0; i--)
    {
        size_t j = (unsigned int)(drand48() * (i + 1));
        card t = deck[j];
        deck[j] = deck[i];
        deck[i] = t;
    }
    return 0;
}

// This method fills the deck with standard poker cards
int init(card deck[])
{
    // Will represent card's pips
    short i;

    for (i = 1; i <= DECK_SIZE; i++)
    {
        // Fill the cards with 1-13
        deck[i - 1].pips = i % 13;
        if (!(i % 13))
            // If i%13 == 0, this card is a king
            deck[i - 1].pips = KING;
        if (i <= 13)
            deck[i - 1].suit = spades;
        else if (i <= 26)
            deck[i - 1].suit = hearts;
        else if (i <= 39)
            deck[i - 1].suit = clubs;
        else
            deck[i - 1].suit = diamonds;
    }
    shuffle(deck);
    return 0;
}

// This method prints len cards
int print_cards(card deck[], int len)
{

    int i;
    for (i = 0; i < len; i++)
    {
        short pip = deck[i].pips;
        switch (deck[i].suit)
        {
        case spades:
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
            break;
        case hearts:
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
            break;
        case clubs:
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
            break;
        case diamonds:
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
            break;
        }
    }
    return 0;
}

// This method gets a card deck and deals a hand of HAND_SIZE size
card *deal_hand(card deck[])
{
    // We shuffle the cards before dealing a hand
    shuffle(deck);
    card *hand = (card *)malloc(HAND_SIZE * sizeof(card));

    int i;
    for (i = 0; i < HAND_SIZE; i++)
    {
        hand[i] = deck[i];
    }
    return hand;
}

// This method checks to see whether a hand has an ace in it
int is_ace_high(card hand[])
{
    int i;
    for (i = 0; i < HAND_SIZE; i++)
    {   
        // If this card is an ace
        if (hand[i].pips == ACE)
            return 1;
    }
    // If we reached here, there is no ace in parameter hand
    return 0;
}

// This method checks to see whether a hand has a pair in it
int is_pair(card hand[])
{
    // Init a counter array, each index represent a possible card pip
    int pips[PIPS] = {0};

    int i;
    
    // Searching the hand for a pair
    for (i = 0; i < HAND_SIZE; i++)
    {
        pips[hand[i].pips - 1]++;
        if (pips[hand[i].pips - 1] == 2)
            return 1;
    }
    return 0;
}

// This method checks to see whether a hand has at least two pairs in it
int is_two_pair(card hand[])
{
    int count = 0, pips[PIPS] = {0}, i;

    for (i = 0; i < HAND_SIZE; i++)
    {
        pips[hand[i].pips - 1]++;
        if (pips[hand[i].pips - 1] == 2)
            count++;
    }
    return (count >= 2);
}

// This method checks to see whether a hand has three of a kind
int is_three(card hand[])
{
    // Init a counter array, each index represent a possible card pip
    int pips[PIPS] = {0}, i;

    for (i = 0; i < HAND_SIZE; i++)
    {
        pips[hand[i].pips - 1]++;

        // If this card appeared three times
        if (pips[hand[i].pips - 1] == 3)
            return 1;
    }

    // If we reached this part of the code, there is no three of a kind in this hand
    return 0;
}



