#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// defines the struct list
typedef struct list{ int data; struct list *next;}list;

// This method returns 1 or 0 based on whether or not argument list is empty
int is_empty(const list *l){ return (l == NULL);}

// This method initializes a head of a list and returns it
list *create_list(int d){
    list *head = malloc(sizeof(list));
    head -> data = d;
    head -> next = NULL;
    return head;
}

// This method takes an integer and a list, creates a new head with argument data and makes it 
// argument list's head. Returns new head
list *add_to_front(int d, list *h){
    list *head = create_list(d);
    head -> next = h;
    return head;
}

// This method takes an array, initializes a new list with arrays elements as elements and
// returns list head
list *array_to_list(int d[], int size){
    list *head = create_list(d[0]);
    int i;
    for(i = 1; i< size; i++){
        head = add_to_front(d[i], head);
    }
    return head;
}