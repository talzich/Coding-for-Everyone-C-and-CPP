#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 100

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

// This method prints the title of parameter list, followed by as line of this list's elements
void print_list(list *h, char *title){
    // Print title for the list
    printf("%s\n", title);
    int i = 0;
    while(h != NULL){

        // If we are at the last element in the list no need for ',' and '\t'
        if(i != SIZE-1)
            printf("%d,\t", h->data);
        else
            printf("%d", h->data);

        // Break line every five elements
        if ((i % 5) == 4)
        {
            printf("\n");
        }
        // Move h to the next node, increment i.
        h = h -> next;
        i++;
    }
    printf("\n");
}

// This method swaps the data of two given pointers to different nodes in a linked list
void swap_nodes(list *p1, list *p2){
    int temp = p1->data;
    p1->data = p2->data;
    p2->data = temp;
    return;
}

// This method uses bubble sort in order to sort a given list
void sort_list(list *h){
    int i, j;
    list *p1, *p2;

    /*  For each iteration we will consider two adjacent pointers
        always starting at the beggining of the list. 
        i will represent the number of times we will move the pointers one step ahead
        decreasing as we bubble more and more element to the end of the list
    */
    for(i = SIZE-2; i >= 0; i--){
        p1 = h;
        p2 = p1->next;
        for(j = 0; j <= i; j++){
            if(p1->data > p2->data)
                swap_nodes(p1, p2);
            p1 = p2;
            p2 = p2->next;
        }
    }

}


int main(void){

    // Starting the list with a random number
    list *l = create_list(rand()%1000);
    
    // Adding (size-1) new elements to the list with a random number
    int i;
    for(i = 0; i < SIZE-1; i++){
        l = add_to_front(rand()%1000, l);
    }
    print_list(l, "Before sorting");
    sort_list(l);
    print_list(l, "After Sorting");
    return 0;
    
}