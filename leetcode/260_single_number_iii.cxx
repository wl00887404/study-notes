#include <iostream>
#include <vector>

using namespace std;

/**
 * 要先寫過 136 再來看這題回比較好
 */

/**
 * 欸不對
 * 寫完 136 我還一樣不會
 * 直接看解答啦
 * https://leetcode.com/problems/single-number-iii/discuss/68921/C%2B%2B-solution-O(n)-time-and-O(1)-space-easy-understaning-with-simple-explanation
 */

/**
 * TODO:
 *   last bit 的操作很鬼耶
 *   討論串有提及 fenwick tree
 *   完全沒看過這個
 */

class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    long long aXorB = 0;  // the result of a xor b;
    for (auto item : nums) aXorB ^= item;

    // int lastBit = (aXorB & (aXorB - 1)) ^ aXorB;
    long long lastBit = aXorB & (-aXorB);

    int intA = 0, intB = 0;
    for (auto item : nums) {
      // based on the last bit, group the items into groupA(include a) and
      // groupB
      if (item & lastBit)
        intA = intA ^ item;
      else
        intB = intB ^ item;
    }
    return vector<int>{intA, intB};
  }
};