#include <iostream>

using namespace :: std;
const double m_to_k = 1.609;

// inline is not widely used thanks to compiler flag "optimize", but this one
// is here for educational purposes

inline double convert(double mi) { return mi*m_to_k; }

int main (void){
	
	// Dr. Pohl used int as an input to mile but I checked it and thought 
	// it would be more appropriate to use double instead
	double miles = 1;
	while(miles != 0){
		cout << "Input distance in miles or 0 to terminate\n";
		cin >> miles;
		// endl is used to create a new line, just like '\n'
		cout << "Distance in kilometers: " << convert(miles) << endl;
	}
	cout << endl;
}
