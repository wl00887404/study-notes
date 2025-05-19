#include <vector>
using namespace std;

/**
 * nums 是不重複的 element，找到總合起來是 target 的組合
 */

/**
 * TODO: blind 75 漏抄題，之後補
 */

class Solution {
 public:
  vector<int>* numsP;
  int target;
  int combinationSum4(vector<int>& nums, int target) {
    numsP = &nums;
    this->target = target;

    return helper(0, target);
  }

  int helper(int index, int target) {
    int count = 0;

    // for(int count  = 0 ;i< )

    return count;
  }
};