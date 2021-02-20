#include <iostream>

using namespace :: std;
const double m_to_k = 1.609;

inline double convert(int mi) { return mi*m_to_k; }

int main (void){

	int miles = 1;
	while(miles != 0){
		cout << "Input distance in miles or 0 to terminate\n";
		cin >> miles;
		cout << "Distance in kilometers: " << convert(miles) << endl;
	}
	cout endl;
}
