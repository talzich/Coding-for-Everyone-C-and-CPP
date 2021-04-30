//
// AUTHOR: Tal Zichlinsky

#include <iostream>

using namespace std;

// Linked list element
struct node{int data; node *next;};

// Singly linked list
class list{

    node *head;
    int size = 0;

    public:
        // Constructor
        list():head(NULL){ cout << "Constructor is called" << endl;}
        
        // Destructor
        ~list(){
            cout << "Destructor is called" << endl;
            node *iter = this->head;
            node *tmp;
            if(iter == NULL) return;

            while(iter->next != NULL){
                tmp = iter->next;
                delete (iter);
                iter = tmp;
            }
        }

        node* get_head() const{
            return this->head;
        }

        void push_back(const int &data){
            
            node *new_node = new node;
            new_node->data = data;
            new_node->next = NULL;

            if(head == NULL){
                head = new_node;
                return;
            }

            node *iter = head;
            while(iter->next != NULL){
                iter = iter->next;
            }
            iter->next = new_node;
        }

        void print_list(){
            
            if(head == NULL) return;

            node *iter = head;
            while(iter->next != NULL){
                cout << "[" << iter->data << "] -> ";
                iter = iter->next;
            }
            cout << "[" << iter->data << "] -> ";
            cout << "(/)" << endl;
        }
};
  
int main(){

    list l{};
    l.print_list();

    l.push_back(1);
    l.print_list();
    
    l.push_back(2);
    l.print_list();

    l.push_back(3);
    l.push_back(4);
    l.push_back(5);

    l.print_list();
    return 0;  
}