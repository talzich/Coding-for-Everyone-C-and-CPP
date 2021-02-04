#include <stdio.h>
#include <stdlib.h>

#define KING 13

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

    if (len != 52)
    {
        printf("Wrong deck size\n");
        return -1;
    }

    int i;
    for (i = 0; i < len - 1; i++)
    {
        int j = i + rand() / (RAND_MAX / (len - i) + 1); // Getting another index from 0 to len-1
        card t = deck[j];
        deck[j] = deck[i];
        deck[i] = t;
    }
    return 0;
}

// This method
int init(card deck[], int len)
{
    short i;
    if (len != 52)
    {
        printf("Wrong deck size\n");
        return -1;
    }
    for (i = 1; i <= len; i++)
    {
        deck[i - 1].pips = i % 13;
        if (!(i % 13))
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
