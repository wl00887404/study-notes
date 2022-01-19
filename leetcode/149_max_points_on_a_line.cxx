#include <math.h>

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 比較快的作法是直接用 slope 斜率
 * 我本來以為 double 有可能會因為小數點丟失 match 不了
 * 只會有一次機會產生 1 與線上其他點連結
 * 0 - 1 - 2 - 3
 * 配對分別是 (0, 1) (0, 2) (0, 3) (1, 2) (1, 3) (2, 3)
 * 只有 0 在配對時剛好會產生答案
 * 所以每次都 clear map 就好
 * 再來再特別計算 x = c 的結果
 */

/**
 * 我大部分的時間都好耗費在 map insert 吧
 */

class Solution {
 public:
  int maxPoints(vector<vector<int>>& points) {
    int result = 0;
    // x = c, 出現次數
    unordered_map<int, int> vertical;
    // y = c, 出現次數
    unordered_map<int, int> horizontal;
    // ax + by = c;, 出現次數
    unordered_map<int, unordered_map<int, unordered_map<int, int>>> diagonal;

    int size = points.size();

    for (int i = 0; i < size; i++) {
      vector<int>& point1 = points[i];
      for (int j = i + 1; j < size; j++) {
        vector<int>& point2 = points[j];

        // 同一個點
        if (point1[0] == point2[0] && point1[1] == point2[1]) {
          continue;
        }

        // x = c
        if (point1[0] == point2[0]) {
          vertical[point1[0]]++;
          result = max(result, vertical[point1[0]]);
          continue;
        }

        // y = c
        if (point1[1] == point2[1]) {
          horizontal[point1[1]]++;
          result = max(result, horizontal[point1[1]]);
          continue;
        }

        // ax + by  = c
        // (y2 - y1) * x + (x1 - x2) * y = c
        int a = point2[1] - point1[1];  // y2 - y1
        int b = point1[0] - point2[0];  // x1 - x2

        int sign = a / abs(a) * b / abs(b);
        int gcd = getGcd(abs(a), abs(b));

        a = abs(a) / gcd * sign;
        b = abs(b) / gcd;
        int c = a * (point1[0]) + b * (point1[1]);

        diagonal[a][b][c]++;
        result = max(result, diagonal[a][b][c]);
      }
    }

    // result 會是 n * (n - 1) / 2
    // 直接公式解 ((-1 * b) + sqrt(b * b - 4 * a * c)) / 2
    // a = 1, b = -1, c = 4n
    return (1 + sqrt(1 + 8 * result)) / 2;
  }

  int getGcd(int a, int b) {
    while (a != 0 && b != 0) {
      a %= b;
      if (a) b %= a;
    }

    return a + b;
  }
};