#include <unordered_map>
#include <vector>
using namespace std;

/**
 * domino 的範圍是 1 ~ 9
 * 順序交換不影響分組，只要小的放前面就好了吧，或是質數乘起來
 *
 * 11, 12, 13, 14, 15, 16, 17, 18, 19
 *     22, 23, 24, 25, 26, 27, 28, 29
 *         33, 34, 35, 36, 37, 38, 39
 */

int PRIME_NUMBERS[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

class Solution {
 public:
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    unordered_map<int, int> map;

    for (vector<int>& domino : dominoes) {
      int key = PRIME_NUMBERS[domino[0] - 1] * PRIME_NUMBERS[domino[1] - 1];

      map[key]++;
    }

    int result = 0;

    for (const pair<int, int>& p : map) {
      result += p.second * (p.second - 1) / 2;
    }

    return result;
  }
};