#include <iostream>
#include <vector>
using namespace std;

/**
 * 從炸彈位置設立禁止區域成功！
 * 禁止區域是十字中心無法出現的位置
 */

/**
 * TODO: 研究 DP 解
 */

class Solution {
 public:
  int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
    if (n == 1) return 0;
    int nn = n * n;
    // order 為十字的一半長
    // order 等於 1 為 1 * 1 的十字
    // order 等於 2 為 3 * 3 的十字
    int order = (n + 1) / 2;

    int blanks = nn - mines.size();
    // 如果十字需要的空間 > 空白格
    while (order * 4 - 3 > blanks) order--;
    if (order == 0) return 0;

    // 中心禁止區域
    int disabledZone[nn];
    for (int i = 0; i < nn; i++) disabledZone[i] = 0;

    // 設置中心禁止區域
    for (vector<int>& mine : mines) {
      int& y = mine[0];
      int& x = mine[1];

      disabledZone[y * n + x]++;
      for (int i = 1; i < order; i++) {
        int top = (y + i) * n + x;
        int bottom = (y - i) * n + x;
        int right = y * n + (x + i);
        int left = y * n + (x - i);

        if (top < nn) disabledZone[top]++;
        if (0 <= bottom) disabledZone[bottom]++;
        if (right < nn) disabledZone[right]++;
        if (0 <= left) disabledZone[left]++;
      }
    };

    while (true) {
      int end = n - order + 1;
      for (int y = order - 1; y < end; y++) {
        for (int x = order - 1; x < end; x++) {
          // 如果中心點範圍內有合法的中心點
          if (!disabledZone[y * n + x] != 0) return order;
        }
      }

      order--;
      if (order == 0) break;
      // 拆除最外圈的炸彈
      for (vector<int>& mine : mines) {
        int& y = mine[0];
        int& x = mine[1];

        int top = (y + order) * n + x;
        int bottom = (y - order) * n + x;
        int right = y * n + (x + order);
        int left = y * n + (x - order);

        if (top < nn) disabledZone[top]--;
        if (0 <= bottom) disabledZone[bottom]--;
        if (right < nn) disabledZone[right]--;
        if (0 <= left) disabledZone[left]--;
      };
    }

    return 0;
  }
} solution;

int main() {
  // int n = 5;
  // vector<vector<int>> mines = {{4, 2}};

  int n = 3;
  vector<vector<int>> mines = {{0, 1}, {0, 2}, {1, 0}, {1, 1},
                               {1, 2}, {2, 0}, {2, 1}, {2, 2}};

  cout << solution.orderOfLargestPlusSign(n, mines) << endl;

  return 0;
}