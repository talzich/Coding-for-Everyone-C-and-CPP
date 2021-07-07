//
// AUTHOR: Dr. Ira Pohl of the University of California. 
// EDITED BY: Tal Zichlinsky
// This file will contain declarations as well as some of the definitions of the list and list_element classes
#include <iostream>

class list_element{
    int data;
    list_element *next;
    public:
        list_element(int n = 0, list_element *next = NULL): data(n), next(next){}
        friend class list;
};// END OF LIST_ELEMENT

class list{
    list_element *head;
    list_element *ptr;
    public:
        list(): head(nullptr), ptr(nullptr){}
        int get_element(){ return ptr->data; }
        void advance(){ ptr = ptr->next; }
        void prepend(int n)
        {
            if(head == nullptr)
            {
                ptr = head = new list_element(n, head);
            }
            else
            {
                head = new list_element(n, head);
            }
        }
        void print()
        {
            list_element *curr = head;
            while(curr != nullptr)
            {
                std::cout << curr->data << ", ";
                curr = curr->next;
            }
            std::cout << "END" << std::endl;
        }
};// END OF LIST