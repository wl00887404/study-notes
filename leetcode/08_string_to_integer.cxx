#include <iostream>
#include <limits>
using namespace std;

class Solution {
 public:
  int myAtoi(string str) {
    string::iterator begin = str.begin();
    string::iterator end = str.end();
    long long result = 0;
    int sign = 1;
    const int max = numeric_limits<int>::max();
    const int min = numeric_limits<int>::min();

    while (*begin == ' ') begin++;

    if (*begin == '+') {
      begin++;
    } else if (*begin == '-') {
      sign = -1;
      begin++;
    }

    while (begin != end) {
      int charCode = (int)*begin;

      if (charCode < 48 || charCode > 57) break;

      result = result * 10 + (charCode - 48) * sign;

      if (result > max) return max;
      if (result < min) return min;

      begin++;
    }

    return result;
  }
} solution;

int main() {
  cout << solution.myAtoi("42") << endl;               // 42
  cout << solution.myAtoi("-42") << endl;              // -42
  cout << solution.myAtoi("4193 with words") << endl;  // 4193
  cout << solution.myAtoi("words and 987") << endl;    // 0
  cout << solution.myAtoi("-91283472332") << endl;     // -2147483648
  cout << solution.myAtoi("+1") << endl;               // 1
  cout << solution.myAtoi("+-2") << endl;              // 0

  return 0;
}