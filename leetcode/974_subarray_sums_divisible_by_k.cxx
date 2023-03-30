#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
/**
 * 老邏輯了
 * 一圈可以靠與先前的結果相減獲得多個結果
 * 譬如 array = [4, 5, 0, -2, -3, 1]
 * [5, 0, -2] = (1, 3) = (0, 3) - (0, 0)
 * 所以兩個情況，一是目前加總是可被 k 整除，二是與前面的相減可以被 k 整除
 */

/**
 * OK 來點優化
 * 針對是可整除的處理應該可行
 * 畢竟只有非整除與非整除要相減處理
 * 整除減去非整除，就還是非整除
 * 所以整除只需要跟整除處理，非整除跟非整除處理
 */

/**
 * 不對，如果全部取餘數
 *   array = [4, 5, 0, -2, -3, 1]
 *     sum = [4, 9, 9,  7,  4, 5]
 * sum % k = [4, 4, 4,  3 , 4, 0]
 * 4 有 4 個， c 4 取 2 為 4 * 3 / 2 = 6
 * 3 有 1 個， c 1 取 2 為 3 * 2 / 2 = 0
 * 0 有 1 個， 本身可以被整除 + c 1 取 2 = 1
 * output 為 7
 */

class Solution {
 public:
  int subarraysDivByK(vector<int>& nums, int k) {
    int size = nums.size();
    int sum = 0;
    int result = 0;
    unordered_map<int, int> remainderFrequency;
    for (int i = 0; i < size; i++) {
      sum += nums[i];
      while (sum < 0) sum += k;
      sum %= k;
      if (!remainderFrequency.count(sum)) {
        remainderFrequency[sum] = 0;
      }
      remainderFrequency[sum]++;
    }

    for (pair<const int, int>& p : remainderFrequency) {
      result += p.second * (p.second - 1) / 2;
      if (p.first == 0) result += p.second;
    }

    return result;
  }
};