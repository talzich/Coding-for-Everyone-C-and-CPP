//AUTHORS: Tal Zichlinsky, Dr. Ira Pohl
// This file is part of week 1 example codes, in particular,
// it is meant to demonstrate the use of generic C++

#include <iostream>

using namespace std;

// This method takes two generic objects, passed by reference, and swaps their values
template<class T>
void generic_swap(T &a, T &b){

        T temp = a;
        a = b;
        b = temp;
}

int main(void){

        int a = 5;
        int b = 3;

        cout << "Before swap a = " << a << " b = " << b << endl;

        swap(a, b);

        cout << "Before swap a = " << a << " b = " << b << endl;

        return 0;
}
