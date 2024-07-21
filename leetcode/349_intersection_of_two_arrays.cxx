#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    bool isExisting[1001];

    for (int i = 0; i < 1001; i++) isExisting[i] = false;

    for (const int& num : nums1) {
      isExisting[num] = true;
    }

    vector<int> result;

    for (const int& num : nums2) {
      if (isExisting[num]) {
        result.push_back(num);
        isExisting[num] = false;
      }
    }

    return result;
  }
};