#include <iostream>
#include <vector>
using namespace std;

/**
 * 找到所有的 subarray，最小值是 minK 最大值是 maxK
 *
 * 一個 min 配一個 max 達成最小條件
 * 不能包含低於 min 與高於 max 的
 *
 * value < min || value > max => boundary => B
 * value == min => required 1 => M
 * value == max => required 2 => N
 * value > min && value < max => optional => O
 *
 * B B B O O O M O O O N O B B
 * 最小滿足是 M O O O N
 * 左側有 3 個可選，右側有 1 個可選
 * (3 + 1) * (1 + 2) = 8
 *
 * 如果 minK 跟 maxK 重複出現，要讓 subarray 盡量短？
 * B M O M O N M O O B
 *           ^ ^
 * 這樣只會算到 NM，不會算到 MON 那組
 *
 * => 遇到新的 M or N，直接計算，更新位置
 */
class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    if (minK == maxK) return countSubarrays(nums, minK);

    int size = nums.size();
    int minIndex = -1;
    int maxIndex = -1;
    long long result = 0;

    int i = 0;
    while (i < size) {
      if (nums[i] < minK || nums[i] > maxK) {
        i++;
        continue;
      }

      int j;
      for (j = i; j < size; j++) {
        const int& num = nums[j];
        if (num < minK || num > maxK) break;

        // 什麼都不是，什麼都不用做
        if (num != minK && num != maxK) continue;

        // 已經有 min 且 max 了
        // 先計算成績，避免重複計算
        if (minIndex != -1 && maxIndex != -1) {
          result += getResult(i, minIndex, maxIndex, j);
        }

        if (num == minK) {
          minIndex = j;
        } else {
          maxIndex = j;
        }
      }

      if (minIndex != -1 && maxIndex != -1) {
        result += getResult(i, minIndex, maxIndex, j);
      }

      minIndex = -1;
      maxIndex = -1;
      i = j;
    }

    return result;
  }

  /**
   * 0 1 2 3 4 5 6 7 8
   * B O O M O O N O B B
   *
   * left = 1, minIndex = 3, maxIndex = 6, rightIndex = 8
   */
  //
  long long getResult(int& left, int& minIndex, int& maxIndex, int& right) {
    // 左側可選
    long long result = min(minIndex, maxIndex) - left + 1;

    // 右側可選
    result *= right - max(minIndex, maxIndex);

    return result;
  }

  long long countSubarrays(vector<int>& nums, int& target) {
    int size = nums.size();
    long long result = 0;

    int i = 0;
    while (i < size) {
      if (nums[i] != target) {
        i++;
        continue;
      }

      int j = i + 1;
      while (j < size && nums[j] == target) {
        j++;
      }

      long long diff = j - i;
      result += diff * (diff + 1) / 2;
      i = j;
    }

    return result;
  }
};