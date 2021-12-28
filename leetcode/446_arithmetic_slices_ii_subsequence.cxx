#include <limits.h>
#include <math.h>

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * daily 當天完全沒空寫，糖糖你先幫我欠著
 * 題意：找出長度至少為三的等差數列們
 */

/**
 * [3, 2, 1 ,1] 竟然答案是 2 ？
 * 所以 index 0 1 2 跟 0 1 3 是兩個解
 * 哇靠北喔
 *
 * 所以 [7, 7, 7, 7, 7] 的答案不會是 7
 * 而是 16
 * 就是所有的 subsequence
 */

/**
 * 2021/11/20
 * 回頭再次想這題
 *
 * 兩兩有機會產生一個等差數列
 */

/**
 * 2021/12/21
 * 這題應該也跟 LCS 公共子序列有關係
 * TODO: 好好想想
 */

class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    size = nums.size();
    if (size < 3) return 0;

    this->numsPointer = &nums;
    unordered_map<long long, int> array[size];
    cache = array;

    for (int i = 0; i < size; i++) {
      int& num = nums[i];
      positionsByNum[num].push_back(i);
    }

    int result = 0;
    for (int i = 0; i < size - 2; i++) {
      for (int j = i + 1; j < size - 1; j++) {
        long long target = (long long)nums[j] + nums[j] - nums[i];
        result += helper(j + 1, target);
      }
    }

    return result;
  }

 private:
  int size;
  unordered_map<int, vector<int>> positionsByNum;
  vector<int>* numsPointer;
  unordered_map<long long, int>* cache;

  // 從 j （包含）開始尋找下一個數字
  int helper(int j, long long& target) {
    if (target > INT_MAX || target < INT_MIN) return 0;
    if (j >= size) return 0;
    if (!positionsByNum.count(target)) return 0;
    if (cache[j].count(target)) return cache[j][target];

    vector<int>& positions = positionsByNum[target];
    int size = positions.size();
    int i = binarySearch(positions, size, j);
    cache[j][target] = 0;

    long long nextTarget = target - (*numsPointer)[j - 1] + target;

    for (; i < size; i++) {
      cache[j][target] += 1 + helper(positions[i] + 1, nextTarget);
    }

    return cache[j][target];
  }

  // 尋找大於等於 j 的位置
  int linearSearch(vector<int>& positions, int& size, int& j) {
    int i = 0;

    while (i < size && positions[i] < j) i++;

    return i;
  }

  int binarySearch(vector<int>& positions, int& size, int& j) {
    int left = 0;
    int right = size;

    while (left < right) {
      int mid = (left + right) / 2;

      if (positions[mid] == j) return mid;
      if (positions[mid] > j) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }
} solution;

int main() {
  // vector<int> nums = {2, 4, 6, 8, 10};
  // vector<int> nums = {2, 4, 6, 8, 12};

  /**
   * FIXME: 這一組在 undordered_map
   * cout(4000000000) 會是 true 耶
   */
  vector<int> nums = {0, 2000000000, -294967296};

  cout << solution.numberOfArithmeticSlices(nums) << endl;

  return 0;
}