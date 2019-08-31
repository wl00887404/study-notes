#include <iostream>
#include <limits>
using namespace std;

class Solution
{
public:
  int reverse(int x)
  {
    long long result = 0;

    const int max = numeric_limits<int>::max();
    const int min = numeric_limits<int>::min();

    while (x != 0)
    {
      int ones = x % 10;

      result *= 10;
      x /= 10;

      result += ones;
      if (result > max || result < min)
        return 0;
    }

    return result;
  }
} solution;

int main()
{
  cout << solution.reverse(-321) << endl;
  return 0;
}