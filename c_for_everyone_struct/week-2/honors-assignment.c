#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define DECK_SIZE 52
#define HAND_SIZE 7
#define STRAIGHT 5
#define FLUSH 5

#define ACE 1
#define KING 13
#define QUEEN 12
#define JACK 11

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

// This method defines a comparison method to the qsort() method used in is_straight()
int comp(const void *a, const void *b)
{
    card *a_card = (card *)a;
    card *b_card = (card *)b;
    return (a_card->pips - b_card->pips);
}

// This method generates straight hands for testing
int straight(card straight_hand[])
{
    int i;
    for (i = 0; i < STRAIGHT; i++)
    {
        straight_hand[i].pips = i + 1;
        straight_hand[i].s = i % 4;
    }
    straight_hand[STRAIGHT + 1].pips = 10;
    straight_hand[STRAIGHT].pips = 8;
    return 0;
}

int straight_flush(card hand[])
{
    int i;
    for (i = 0; i < STRAIGHT; i++)
    {
        hand[i].pips = i + 1;
        hand[i].s = spades;
    }
    hand[STRAIGHT + 1].pips = 10;
    hand[STRAIGHT].pips = 8;
    return 0;
}

// This method gets a deck of cards and shuffles it
// It ensures that the array will be shuffled based on a random seed taken from the usec time.
// Found that great array shuffler at https://stackoverflow.com/questions/6127503/shuffle-array-in-c
int shuffle(card deck[], int len)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    int usec = tv.tv_usec;
    srand48(usec);

    if (len > 1)
    {
        size_t i;
        for (i = len - 1; i > 0; i--)
        {
            size_t j = (unsigned int)(drand48() * (i + 1));
            card t = deck[j];
            deck[j] = deck[i];
            deck[i] = t;
        }
    }
    return 0;
}

// This function prints the deck according to its current order
int print_cards(card deck[], int len)
{

    int i;
    for (i = 0; i < len; i++)
    {
        short pip = deck[i].pips;
        switch (deck[i].s)
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

// This function gets a card deck and deals a hand of desired size
card *deal_hand(int hand_size, card deck[])
{

    if (hand_size > DECK_SIZE)
    {
        printf("Invalid hand size requested\n");
        return NULL;
    }
    // We shuffle the cards before dealing a hand
    shuffle(deck, DECK_SIZE);
    card *hand = (card *)malloc(HAND_SIZE * sizeof(card));

    int i;
    for (i = 0; i < hand_size; i++)
    {
        hand[i] = deck[i];
    }
    return hand;
}

// This function checks to see whether a hand has an ace in it
int is_ace_high(card hand[], int hand_size)
{
    int i;
    for (i = 0; i < hand_size; i++)
    {
        if (hand[i].pips == 1)
            return 1;
    }
    return 0;
}

// This function checks to see whether a hand has a pair in it
int is_pair(card hand[], int hand_size)
{
    int pips[13] = {0};
    int i;
    for (i = 0; i < hand_size; i++)
    {
        pips[hand[i].pips - 1]++;
        if (pips[hand[i].pips - 1] == 2)
            return 1;
    }
    return 0;
}

// This function checks to see whether a hand has two pairs in it
int is_two_pair(card hand[], int hand_size)
{
    int count = 0;
    int pips[13] = {0};
    int i;
    for (i = 0; i < hand_size; i++)
    {
        pips[hand[i].pips - 1]++;
        if (pips[hand[i].pips - 1] == 2)
            count++;
    }
    return (count >= 2);
}

// This function checks to see whether a hand has three of a kind
int is_three(card hand[], int hand_size)
{

    int pips[13] = {0};
    int i;
    for (i = 0; i < hand_size; i++)
    {
        pips[hand[i].pips - 1]++;
        if (pips[hand[i].pips - 1] == 3)
            return 1;
    }
    return 0;
}

// This function checks to see whether a hand has a straight in it
int is_straight(card hand[], int hand_size)
{
    qsort(hand, hand_size, sizeof(card), comp);
    int i, count = 1, royale_flag = 2;

    // Straight ace high
    if(hand[0].pips == ACE && hand[hand_size-1].pips == KING){
        for(i = 1; i<hand_size-1; i++){
            switch (hand[i].pips)
            {
            case QUEEN:
                royale_flag++;
                break;
            case JACK:
                royale_flag++;
                break;
            case 10:
                royale_flag++;
                break;
            }
            if(royale_flag == 5){
                return 1;
            }
        }
    }

    
    for (i = hand_size - 1; i >= 1; i--)
    {
        if ((hand[i].pips - hand[i - 1].pips) == 1)
        {
            count++;
            if (count == STRAIGHT)
                return 1;
        }
        else
            count = 1;
    }
    return (count == STRAIGHT);
}

// This function checks to see whether a hand has a flush in it
int is_flush(card hand[], int hand_size)
{
    int spades_count = 0;
    int hearts_count = 0;
    int clubs_count = 0;
    int diamonds_count = 0;

    int i, suit;
    for (i = 0; i < hand_size; i++)
    {
        suit = hand[i].s;
        switch (suit)
        {
        case spades:
            spades_count++;
            if (spades_count == FLUSH)
                return 1;
            break;
        case hearts:
            hearts_count++;
            if (hearts_count == FLUSH)
                return 1;
            break;
        case clubs:
            clubs_count++;
            if (clubs_count == FLUSH)
                return 1;
            break;
        case diamonds:
            diamonds_count++;
            if (diamonds_count == FLUSH)
                return 1;
            break;
        }
    }
    return 0;
}

// This function checks to see whether a hand is a full house
int is_full_house(card hand[], int hand_size)
{
    int pips[13] = {0};
    int i;
    for (i = 0; i < hand_size; i++)
    {
        pips[hand[i].pips - 1]++;
    }

    int pair_flag, three_flag;
    for (i = 0; i < 13; i++)
    {
        if (pips[i] == 2)
            pair_flag = 1;
        else if (pips[i] == 3)
            three_flag = 1;
    }
    return (pair_flag && three_flag);
}

// This function checks to see whether a hand has four of a kind
int is_four(card hand[], int hand_size)
{
    int pips[13] = {0};
    int i;
    for (i = 0; i < hand_size; i++)
    {
        pips[hand[i].pips - 1]++;
        if (pips[hand[i].pips - 1] == 4)
            return 1;
    }
    return 0;
}

// This function checks to see whether a hand is a straight flush
int is_straight_flush(card hand[], int hand_size, card straight[])
{
    qsort(hand, hand_size, sizeof(card), comp);

    int i, j = 0, count = 1;
    for (i = hand_size - 1; i >= 1; i--)
    {
        if ((hand[i].pips - hand[i - 1].pips) == 1 && hand[i].s == hand[i - 1].s)
        {
            count++;
            straight[j++] = hand[i];
            if (count == STRAIGHT)
                return 1;
        }
        else{
            count = 1;
            j = 0;
        }
    }
    return (count == STRAIGHT);
}

// This function checks to see whether a hand is a royale flush
int is_royale_flush(card hand[], int hand_size)
{
    card royals[FLUSH];
}


int main(void)
{
    card deck[52];
    init(deck);
    card *hand = deal_hand(HAND_SIZE, deck);
    card straight[STRAIGHT];
    printf("Ace: %d\n", is_ace_high(hand, HAND_SIZE));
    printf("Pair: %d\n", is_pair(hand, HAND_SIZE));
    printf("Two pair: %d\n", is_two_pair(hand, HAND_SIZE));
    printf("Three of a Kind: %d\n", is_three(hand, HAND_SIZE));
    printf("Straight: %d\n", is_straight(hand, HAND_SIZE));
    printf("Flush: %d\n", is_flush(hand, HAND_SIZE));
    printf("Full House: %d\n", is_full_house(hand, HAND_SIZE));
    printf("Four of a Kind: %d\n", is_four(hand, HAND_SIZE));
    printf("Straight flush: %d\n", is_straight_flush(hand, HAND_SIZE, straight));
    printf("Royale flush: %d\n", is_royale_flush(hand, HAND_SIZE));
    printf("\n");
    print_cards(hand, HAND_SIZE);
    return 0;
}
