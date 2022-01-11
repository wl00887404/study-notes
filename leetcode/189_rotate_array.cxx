#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 原來是要往右推
 */

// 複製重複的部份
class FirstSolution {
 public:
  void rotate(vector<int>& nums, int k) {
    int size = nums.size();
    k = size - k % size;
    nums.resize(size + k);

    for (int i = 0; i < k; i++) {
      nums[size + i] = nums[i];
    }

    for (int i = 0; i < size; i++) {
      nums[i] = nums[i + k];
    }

    nums.resize(size);
  }
};

/**
 * 一個一個移會 GG
 * 要是一次移動 k 個位置呢？
 * [0, 1, 2, 3, 4, 5]
 *
 * k = 2, lcm 是 6, 6 / 2 為 3, 一次只能處理 3 個
 * 0 => 2, 2 => 4, 4 => 0
 * 1 => 3, 3 => 5, 5 => 1
 *
 * k = 3, lcm 是 6, 6 / 3 為 2, 一次只能處理 2 個
 * 0 => 3, 3 => 0
 * 1 => 4, 4 => 1
 * 2 => 5, 5 => 2
 *
 * k = 4, lcm 是 12, 12 / 4 為 3, 一次只能處理 3個
 * 0 => 4, 4 => 2, 2 => 0
 *
 *
 * 要是 [0, 1, 2, 3, 4, 5, 6]
 *
 * k = 4
 * 0 => 4, 4 => 1, 1 => 5, 5 => 2, 2 => 6, 6 => 3, 3 => 0
 *
 * k = 3
 * 0 => 3, 3 => 6, 6 => 2, 2 => 5, 5 => 1, 1 => 4, 4 => 0
 */

class SecondSolution {
 public:
  void rotate(vector<int>& nums, int k) {
    numsPointer = &nums;
    size = nums.size();
    this->k = k % size;
    if (this->k == 0) return;

    int gcd = calcGcd(size, this->k);

    /**
     * 每次能夠處理的個數為
     * x * y / gcd / y
     *   = x / gcd
     *
     * 總共需要做 gcd 次
     */

    while (gcd--) shiftRight(gcd);
  }

  vector<int>* numsPointer;
  int k;
  int size;

  void shiftRight(int i) {
    vector<int>& nums = *numsPointer;
    int j = i;
    int temp = nums[i];

    while (true) {
      int nextJ = (j + k) % size;
      int nextTemp = nums[nextJ];

      nums[nextJ] = temp;

      j = nextJ;
      temp = nextTemp;
      if (i == j) break;
    }
  }

  int calcGcd(int x, int y) {
    while ((x %= y) != 0 && (y %= x) != 0) {
    }

    return x + y;
  }

  void shiftRight1() {
    vector<int>& nums = *numsPointer;
    int temp = nums[size - 1];

    for (int i = size - 1; 0 < i; i--) {
      nums[i] = nums[i - 1];
    }

    nums[0] = temp;
  }
};

/**
 * 與 FirstSolution 只複製 k 個位置比起來
 * 其實使用的記憶體差不多
 */
class ThirdSolution {
 public:
  void rotate(vector<int>& nums, int k) {
    vector<int> temp(nums.size());

    for (int i = 0; i < nums.size(); i++) {
      temp[(i + k) % nums.size()] = nums[i];
    }

    nums = temp;
  }
};

/**
 * https://leetcode.com/problems/rotate-array/discuss/54252/Java-O(1)-space-solution-of-Rotate-Array.
 * 討論區看到的
 * 這個 reverse 挺厲害的
 *
 * TODO: 忘記了再回來複習一下
 */
class FourSolution {
 public:
  void rotate(vector<int>& nums, int k) {
    k %= nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};

class Solution : public FourSolution {};
