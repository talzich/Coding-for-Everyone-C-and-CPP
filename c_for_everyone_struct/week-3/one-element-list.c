#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// defines the struct list
typedef struct list{ int data; struct list *next;}list;

// This method returns 1 or 0 based on whether or not argument list is empty
int is_empty(const list *l){ return (l == NULL);}

// This method prints the title of parameter list, followed by as line of this list's elements
void print_list(list *h, char *title){
    printf("%s\n", title);
    while(h != NULL){
        printf("%d :", h->data);
        printf("\n");
        h = h->next;
    }
}

int main(void){
    list list_of_int;
    list *head = NULL;
    head = malloc(sizeof(list));
    head -> data = 5;
    head -> next = NULL;
    print_list(head, "single element list");
    printf("\n");
    return 0;
}


