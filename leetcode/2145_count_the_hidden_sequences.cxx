#include <iostream>
#include <vector>
using namespace std;

/**
 * differences = [1, -3, 4], lower = 1, upper = 6
 *
 * 陣列共 4 項，分別是 [n, n + 1, n - 2, n + 2]
 * 最小是 n - 2，最大是 n + 2
 *
 * 假設最小是 lower => n - 2 = 1 => n = 3, max = 3 + 2 = 5, 小於 upper
 * 假設最大是 upper => n + 2 = 6 => n = 4, min = 4 - 2 = 2, 大於 lower
 *
 * 全數量 = 4 - 3 + 1 = 2
 */

class Solution {
 public:
  int numberOfArrays(vector<int>& differences, int lower, int upper) {
    long long minimum = 0;
    long long maximum = 0;
    long long sum = 0;

    for (int& difference : differences) {
      sum += difference;
      minimum = min(minimum, sum);
      maximum = max(maximum, sum);
    }

    int nRange = maximum - minimum;
    int range = upper - lower;

    if (nRange > range) return 0;

    return range - nRange + 1;
  }
};