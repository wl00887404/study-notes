#include <vector>
using namespace std;

/**
 * 要是 nums 有排序，找到最大的 nums[i + 1] - nums[i]
 * 這題要求一定要 Time O(n) + Space O(1)
 */

/**
 * 沒有排序怎麼知道自己相鄰誰啦
 * [1, 99, 6, 4, 19]
 * 1  => [0, -98, -5, -3, -18] => -3
 * 99 => [98, 0, 93, 95, 80] => 80
 * 6 => [5, -93, 0, 2, -13] => 2, -13
 * 4 => [3, -95, -2, 0, -15] => -2, 3
 * 19 => [18, -80, 13, 15, 0] => 13, -80
 *
 * 找負數最大，正數最小，就是相鄰距離
 *
 * 平均數 avg 有幫助嗎？
 */

/**
 * TODO: 還沒寫完的 hard
 */

class Solution {
 public:
  int maximumGap(vector<int>& nums) { return 0; }
};