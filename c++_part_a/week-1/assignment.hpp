#include <vector>
#include <numeric>

const short N = 40;

inline int
sum(vector<int> data)
{ return std::accumulate(data.begin(), data.end(), 0); }