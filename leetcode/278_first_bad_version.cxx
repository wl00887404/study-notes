#include <iostream>
#include <unordered_map>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
bool isBadVersion(int version) { return version >= 4; }

class Solution {
 public:
  int firstBadVersion(int n) {
    int left = 1;
    int right = n;

    while (left < right) {
      int mid = left + (right - left) / 2;

      if (isBadVersion(mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }
} solution;

int main() {
  cout << solution.firstBadVersion(5) << endl;

  return 0;
}