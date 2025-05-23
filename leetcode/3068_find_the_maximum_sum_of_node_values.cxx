#include <iostream>
#include <vector>
using namespace std;

/**
 * 給一個無向的樹，值放在 nums，並用 edges 表示他們的關係
 * 可以做一種操作，選擇任一 edge，同時 XOR k 連結他的兩個節點
 * 可以做無限次，求樹最後總和最高
 *
 * 一個數字 XOR k 又再次 XOR k 就會變回來吧
 * 所以以我可以任意兩個數字 XOR K ，選最大的偶數個
 *
 * 最好的情況，有偶數個數字 XOR 後總和增加
 * 或是有一個人 XOR 增加，但是配一個 XOR 變少，總和還是成長
 *
 * 這裡的 edges 有意義嗎？
 *
 * 還有一個情境是全體 XOR 都是正的，但是有奇數個，所以不能全收
 *
 * 再次統整一下
 * 有正有負 => 前偶數個正數加上，或是奇數個正數加上一個非正數
 * 全部正 => 前偶數個正數加上
 * 全部負 => 沒搞頭直接回傳
 */

 /**
  * 2025/5/23
  * 突然殺了一題 hard，還挺開心的
  */

class Solution {
 public:
  long long maximumValueSum(vector<int>& nums, int k,
                            vector<vector<int>>& edges) {
    int size = nums.size();
    long long sum = 0;
    int positiveCount = 0;
    int smallestPositiveDiff = INT_MAX;
    int largestNotPositiveDiff = INT_MIN;

    for (int i = 0; i < size; i++) {
      sum += nums[i];
      int diff = (nums[i] ^ k) - nums[i];

      if (diff > 0) {
        positiveCount++;
        sum += diff;
        smallestPositiveDiff = min(smallestPositiveDiff, diff);
      } else {
        largestNotPositiveDiff = max(largestNotPositiveDiff, diff);
      }
    }

    // 正數有偶數個，可以全收
    if (positiveCount % 2 == 0) return sum;

    // 正數有奇數個，必須少收一個正數，或是多收一個非正數
    return max(sum - smallestPositiveDiff, sum + largestNotPositiveDiff);
  }
};