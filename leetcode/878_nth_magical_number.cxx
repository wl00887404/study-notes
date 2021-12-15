#include <iostream>

using namespace std;

/**
 * 假設是 30 42
 * greatest common divisor 是 6
 * least common multiple 就是 30 / 6 * 42 = 210
 * 不包含 210
 * 30 能產生 6 個分別是 30, 60, 90, 120, 150, 180
 * 42 能產生 4 個 42, 84, 126, 168
 */

class Solution {
 public:
  int nthMagicalNumber(int n, int a, int b) {
    int gcd = calcGcd(a, b);
    long long lcm = a / gcd * b;
    // 一輪能夠產生的 magical numbers
    int count = lcm / a + lcm / b - 1;

    long long result = lcm * (n / count);
    n %= count;

    int maybeA = 0;
    int maybeB = 0;

    for (int i = 0; i < n; i++) {
      if (maybeA + a > maybeB + b) {
        maybeB += b;
      } else {
        maybeA += a;
      }
    }

    return (result + max(maybeA, maybeB)) % 1000000007;
  }

  int calcGcd(int a, int b) {
    while ((a %= b) && (b %= a)) {
    };
    return a + b;
  }
} solution;

int main() {
  cout << solution.nthMagicalNumber(1000000000, 40000, 40000) << endl;

  return 0;
}