#include <iostream>
using namespace std;

/**
 * 如果 n = 3 可走 1 、 2 格子
 * 那就從 n = 1 與 n = 2 來
 */

class Solution {
 public:
  int climbStairs(int n) {
    int cache[46];
    for (int i = 0; i < 46; i++) cache[i] = -1;
    cache[1] = 1;  // 1
    cache[2] = 2;  // 1 + 1, 2

    return climbStairs(n, cache);
  }
  int climbStairs(int n, int* cache) {
    if (cache[n] != -1) return cache[n];

    int result = climbStairs(n - 1, cache) + climbStairs(n - 2, cache);
    cache[n] = result;

    return result;
  }
} solution;

int main() {
  solution.climbStairs(6);

  return 0;
}