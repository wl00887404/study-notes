#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 題意：
 *   把陣列變成 [a, b, a, b, a] 的陣列
 *   其中 a 不能等於 b
 */

/**
 * 這題有夠麻煩的
 */

class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    // 偶數 index 出現次數
    unordered_map<int, int> m1;
    // 奇數 index 出現次數
    unordered_map<int, int> m2;
    int size = nums.size();
    if (size == 1) return 0;

    int most1;
    bool isSet1 = false;
    for (int i = 0; i < size; i += 2) {
      m1[nums[i]]++;

      if (!isSet1 || m1[most1] < m1[nums[i]]) {
        isSet1 = true;
        most1 = nums[i];
      }
    }

    int most2;
    bool isSet2 = false;
    for (int i = 1; i < size; i += 2) {
      m2[nums[i]]++;

      if (!isSet2 || m2[most2] < m2[nums[i]]) {
        isSet2 = true;
        most2 = nums[i];
      }
    }

    // 奇偶最常出現的不一樣
    if (most1 != most2) return size - m1[most1] - m2[most2];

    if (m1.size() == 1 && m2.size() == 1) {
      // 媽的這個陣列完全一樣
      return size / 2;
    }

    if (m1.size() == 1) {
      // 沒有第二種偶數項了
      int prevMost2 = most2;
      isSet2 = false;

      for (const pair<int, int>& p : m2) {
        if (p.first == prevMost2) continue;

        if (!isSet2 || m2[most2] < p.second) {
          isSet2 = true;
          most2 = p.first;
        }
      }

      return size - m1[most1] - m2[most2];
    }

    if (m2.size() == 1) {
      // 沒有第二種奇數項了
      int prevMost1 = most1;
      isSet1 = false;

      for (const pair<int, int>& p : m1) {
        if (p.first == prevMost1) continue;

        if (!isSet1 || m1[most1] < p.second) {
          isSet1 = true;
          most1 = p.first;
        }
      }

      return size - m1[most1] - m2[most2];
    }

    // 兩者都有第二選項

    int most3;
    bool isSet3 = false;

    for (const pair<int, int>& p : m1) {
      if (p.first == most1) continue;

      if (!isSet3 || m1[most3] < p.second) {
        isSet3 = true;
        most3 = p.first;
      }
    }

    int most4;
    bool isSet4 = false;

    for (const pair<int, int>& p : m2) {
      if (p.first == most2) continue;

      if (!isSet4 || m2[most4] < p.second) {
        isSet4 = true;
        most4 = p.first;
      }
    }

    return min(size - m1[most1] - m2[most4], size - m1[most3] - m2[most2]);
  }
};