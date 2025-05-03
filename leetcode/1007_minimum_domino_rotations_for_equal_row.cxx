#include <vector>

using namespace std;

/**
 * 2025/5/3 每日一題
 * 本來中午起床就打算要寫，結果拖了八小時才打算開始
 */
/**
 * 數字一共 1 ~ 6
 * 分為 tops 與 bottoms，能夠做的操作是上下交換
 * 問最少交換幾次可以把整條變成一樣的數字，辦不到回傳就 -1
 *
 * 因為只能上下交換，所以某個數字一定要出現在 tops[i] 或是 bottoms[i]
 */

class Solution {
 public:
  int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    int size = tops.size();
    vector<int> topFrequencies(6, 0);
    vector<int> bottomFrequencies(6, 0);
    vector<int> sameFrequencies(6, 0);

    // 統計所有數字的出現次數
    for (int i = 0; i < size; i++) {
      topFrequencies[tops[i] - 1]++;
      bottomFrequencies[bottoms[i] - 1]++;

      if (tops[i] == bottoms[i]) {
        sameFrequencies[tops[i] - 1]++;
      }
    }

    // 找能夠組成整個陣列的數字
    for (int i = 0; i < 6; i++) {
      if (topFrequencies[i] + bottomFrequencies[i] - sameFrequencies[i] ==
          size) {
        return min(topFrequencies[i], bottomFrequencies[i]) -
               sameFrequencies[i];
      }
    }

    // 沒找到
    return -1;
  }
};