#include <iostream>
#include <unordered_set>
using namespace std;

/**
 * 不快樂的數字會有不快樂循環耶
 *  4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4
 * 酷
 */
class Solution {
 public:
  bool isHappy(int n) {
    unordered_set<int> cache;
    return helper(n, cache);
  }

 private:
  bool helper(int& n, unordered_set<int>& cache) {
    if (cache.count(n)) return false;

    int tempN = n;
    int nextN = 0;

    while (tempN) {
      nextN += (tempN % 10) * (tempN % 10);
      tempN /= 10;
    }

    if (nextN == 1) return true;

    cache.insert(n);

    return helper(nextN, cache);
  }
} solution;



int main() {
  cout << solution.isHappy(19) << endl;
  return 0;
}