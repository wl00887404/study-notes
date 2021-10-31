#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int round = 0;
    int freshCount = 0;

    queue<int> rottenI;
    queue<int> rottenJ;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) freshCount++;
        if (grid[i][j] == 2) {
          rottenI.push(i);
          rottenJ.push(j);
          grid[i][j] = 0;
        }
      }
    }

    while (!rottenI.empty() && freshCount != 0) {
      round++;
      int length = rottenI.size();

      while (length--) {
        int& i = rottenI.front();
        int& j = rottenJ.front();

        if (0 <= i - 1 && grid[i - 1][j] == 1) {
          grid[i - 1][j] = 0;
          freshCount--;
          rottenI.push(i - 1);
          rottenJ.push(j);
        }

        if (i + 1 < m && grid[i + 1][j] == 1) {
          grid[i + 1][j] = 0;
          freshCount--;
          rottenI.push(i + 1);
          rottenJ.push(j);
        }

        if (0 <= j - 1 && grid[i][j - 1] == 1) {
          grid[i][j - 1] = 0;
          freshCount--;
          rottenI.push(i);
          rottenJ.push(j - 1);
        }

        if (j + 1 < n && grid[i][j + 1] == 1) {
          grid[i][j + 1] = 0;
          freshCount--;
          rottenI.push(i);
          rottenJ.push(j + 1);
        }

        rottenI.pop();
        rottenJ.pop();
      }
    }

    return freshCount == 0 ? round : -1;
  }
};