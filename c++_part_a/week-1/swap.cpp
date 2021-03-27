// 
// AUTHORS: Tal Zichlinsky, Dr. Ira Pohl
// This file is part of week 1 example codes, in particular, 
// it is meant to demonstrate the use of passing parameters by reference in C++

#include <iostream>

using namespace std;

// This method takes to integers, passed by reference, and swaps their values
void swap(int &a, int &b){

	int temp = a;
	a = b;
	b = temp;
}

int main(void){

	int a = 5; 
	int b = 3;
	cout << "Before swapping a = " << a << " b = " << b << endl;
	
	swap(a, b);
	
	cout << "After swapping a = " << a << " b = " << b << endl;

	return 0;
}

