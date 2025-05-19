#include <vector>

using namespace std;

class Solution2021 {
 public:
  void sortColors(vector<int>& nums) {
    int red = 0;
    int white = 0;
    int blue = 0;

    for (int& num : nums) {
      if (num == 0) red++;
      if (num == 1) white++;
      if (num == 2) blue++;
    }

    int i = 0;

    while (red--) {
      nums[i] = 0;
      i++;
    }

    while (white--) {
      nums[i] = 1;
      i++;
    }
    while (blue--) {
      nums[i] = 2;
      i++;
    }
  }
};

/**
 * 2021 寫過，2025 寫了差不多的解法
 *
 * 如果要求是 Space = O(1), Time = n
 * 應該是 0 放最前面、2 放最後面，兩邊夾起來中間放 1
 *
 * 看了 discussion 這叫 Dutch national flag problem
 * 也就是荷蘭國旗是紅白藍
 */
class Solution2025 {
 public:
  void sortColors(vector<int>& nums) {
    int counts[3] = {0};

    for (const int& num : nums) {
      counts[num]++;
    }

    int i = 0;
    for (int j = 0; j < 3; j++) {
      while (counts[j]--) {
        nums[i] = j;
        i++;
      }
    }
  }
};

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int left = 0;             // 第一個 1 的位置
    int right = nums.size();  // 第一個 2 的位置
    int i = 0;

    while (i < right) {
      if (nums[i] == 0) {
        swap(nums[left], nums[i]);
        left++;
        i++;
      } else if (nums[i] == 1) {
        i++;
      } else {
        // nums[i] == 2
        swap(nums[i], nums[right - 1]);
        right--;
      }
    }
  }

  void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
  }
};
