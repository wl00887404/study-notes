
#include <vector>
using namespace std;

/**
 * 找到陣列內數字是兩位數、四位數，依此類推
 *
 * 2: 10 <= n <= 99
 * 4: 1000 <= n <= 9999
 * 6: 100000 <= n <= 999999
 *
 * number 最大是 6 位數
 */

class Solution {
 public:
  int findNumbers(vector<int>& nums) {
    int result = 0;

    for (const int& num : nums) {
      if (10 <= num && num <= 99 || 1000 <= num && num <= 9999 ||
          num == 100000) {
        result++;
      }
    }

    return result;
  }
};