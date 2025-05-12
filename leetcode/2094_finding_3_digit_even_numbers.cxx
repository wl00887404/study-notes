#include <vector>
using namespace std;

/**
 * 找到所有偶數組合，不能有 leading 0 與奇數
 */

class Solution {
 public:
  vector<int> findEvenNumbers(vector<int>& digits) {
    vector<int> counts(10, 0);

    for (const int& i : digits) {
      counts[i]++;
    }

    vector<int> result;

    for (int i = 1; i < 10; i++) {
      if (counts[i] == 0) continue;
      counts[i]--;
      for (int j = 0; j < 10; j++) {
        if (counts[j] == 0) continue;
        counts[j]--;

        for (int k = 0; k < 10; k += 2) {
          if (counts[k] == 0) continue;
          result.push_back(i * 100 + j * 10 + k);
        }

        counts[j]++;
      }
      counts[i]++;
    }

    return result;
  }
};