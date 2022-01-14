#include <iostream>
#include <vector>

using namespace std;

/**
 * 流程是這樣：
 *
 * 1. 進加油站加油
 * 2. 檢查能不能開車
 * 3. 開車減少汽油
 * 4. 重複 1
 *
 *         0  1  2  3  4
 * gas  = [1, 2, 3, 4, 5]
 * cost = [3, 4, 5, 1, 2]
 *
 * 靠北
 * 從 [3] 開車到 [4] 的 cost 是 cost[3] 喔
 */

/**
 * 每個 delta 都是固定的
 * 從 [0] 到 [1] 一定是 -2 gas
 *
 * 起始點不一樣會覺得過程有沒有機會變負的
 *   gas = [ 1,  2,  3, 4, 5]
 *  cost = [ 3,  4,  5, 1, 2]
 * delta = [-2, -2, -2, 3, 3]
 *
 * 假設我從 [0] 開始
 * gas 變化分別是 -2, -4, -6, -3, 0
 * 最慘要有 6 點 gas 才行
 *
 * [0]: -2, -4, -6,  -3, 0 | min = -6
 * [1]: -2, -4, -1,   2, 0 | min = -4
 * [2]: -2,  1,  4,   2, 0 | min = -2
 * [3]:  3,  6,  4,   2, 0 | min =  0 （這點可以）
 * [4]:  3,  1, -1,  -3, 0 | min = -3
 *
 *   gas = [ 2,  3, 4]
 *  cost = [ 3,  4, 3]
 * delta = [-1, -1, 1]
 *
 * [0]: -1, -2, -1 | min = -2
 * [1]: -1,  0, -1 | min = -1
 * [2]:  1,  0, -1 | min = -1
 *
 * 原本的最低點要是不見了就不能用推的了
 * 欸不對
 * 答案就是最低點的下一個吧
 */

class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int size = gas.size();
    int minIndex;
    int minGasTank = 0;
    int gasTank = 0;

    for (int i = 0; i < size; i++) {
      gasTank += gas[i] - cost[i];

      if (gasTank < minGasTank) {
        minGasTank = gasTank;
        minIndex = i;
      }
    }

    if (minGasTank >= 0) return 0;
    // if (minIndex == size - 1) return -1;

    int targetIndex = (minIndex + 1) % size;

    gasTank = 0;
    for (int i = targetIndex; i < size; i++) {
      gasTank += gas[i] - cost[i];

      if (gasTank < 0) return -1;
    }

    if (gasTank + minGasTank < 0) return -1;

    return targetIndex;
  }
};