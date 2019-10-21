#include <cmath>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, double> map;

class Solution {
 public:
  double myPow(double x, int n) {
    if (n == 0) return 1;

    if (n < 0) return 1 / myPow(x, -1 * n);

    if (n == 1) return x;

    /*
     * if n = 17
     * 有 return / 沒有找 8 + 8 + 1 存 cache
     * then if n = 8
     * 有 return / 沒有找 4 + 4 存 cache
     */

    double result = 1;
    double f = x;
    while (n != 0) {
      if (n % 2 == 1) result *= f;
      n >>= 1;
      f *= f;
    }
    return result;
  }
} solution;

int main() {
  cout << solution.myPow(2.10000, 3) << endl;
  cout << 2.1 * 2.1 * 2.1 << endl;
  return 0;
}