/*   Convert this program to C++

*   change to C++ io

*   change to one line comments

*   change defines of constants to const

*   change array to vector<>

*   inline any short function

*/

#include <iostream>
#include <array>
#include <vector>
#include <numeric>

using namespace std;

// Replacing the #define
const short N = 40;

// Inlining the function, as requested in the prompt
inline int
sum(vector<int> data)
{ return accumulate(data.begin(), data.end(), 0); }

int main(void){
  
  int accum = 0;
  vector<int> data (N);

  // Filling vector
  for (int i = 0; i < N; ++i)
  {
    data[i] = i;
  }
  accum = sum(data);

  // Printing the outcome using cout instead of printf
  cout << "Sum is " << accum << endl;

  return 0;
}
