//
// AUTHOR: Dr. Ira Pohl of the University of California. 
// EDITED BY: Tal Zichlinsky
// COMPILE WITH: clang++ -std=c++2a
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
    list_element *arbitrary_ptr;
    list_element *end_ptr;
    public:
        list(): head(nullptr), arbitrary_ptr(nullptr){}

        list(const int *arr, int n) :head(nullptr), arbitrary_ptr(nullptr)
        {
            if(n >= 1)
            {
                for(int i = 0; i < n; ++i)
                {
                    append(arr[i]);
                }
            }   
        }

        list(const list &other)
        {
            
        }
        
        int get_element(){ return arbitrary_ptr->data; }
        
        void advance(){ arbitrary_ptr = arbitrary_ptr->next; }
        
        void prepend(int n)
        {
            if(head == nullptr)
            {
                arbitrary_ptr = head = end_ptr = new list_element(n, head);
            }
            else
            {
                head = new list_element(n, head);
            }
        }
        
        void append(int n)
        {
            if(head == nullptr)
            {
                arbitrary_ptr = head = end_ptr = new list_element(n, NULL);
            }
            else
            {
                end_ptr->next = new list_element(n, NULL);
                end_ptr = end_ptr->next;
            }
        }
        
        void print()
        {
            list_element *curr = head;
            while(curr != nullptr)
            {
                std::cout << curr->data << " -> ";
                curr = curr->next;
            }
            std::cout << "END" << std::endl;
        }
};// END OF LIST

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    list l{arr, 10};
    // for(int i = 1; i <= 5; ++i)
    // {
    //     l.append(i);
    // }
    // for(int i = 6; i <= 10; ++i)
    // {
    //     l.prepend(i);
    // }
    l.print();
}