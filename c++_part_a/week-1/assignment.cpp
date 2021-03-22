/*   Convert this program to C++

*   change to C++ io

*   change to one line comments

*   change defines of constants to const

*   change array to vector<>

*   inline any short function

*/

#include <iostream>
#include <array>
#include "assignment.hpp"

using namespace std;

int main(void){
  
  int accum = 0;
  

  vector<int> data (N);
  
  cout << "Test" << endl;

  // Initializing vector elements
  for (int i = 0; i < N; ++i)
  {
    data[i] = i;
  }
  accum = sum(data);

  cout << "Sum is " << accum << endl;

  return 0;
}
