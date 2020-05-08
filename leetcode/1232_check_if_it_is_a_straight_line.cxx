#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool checkStraightLine(vector<vector<int>>& coordinates) {
    int length = coordinates.size();

    if (length == 2) return true;

    double dx = coordinates[1][0] - coordinates[0][0];
    double dy = coordinates[1][1] - coordinates[0][1];

    if (dy == 0) {
      for (int i = 2; i < length; i++) {
        if (coordinates[i][1] != coordinates[0][1]) return false;
      }

      return true;
    }

    if (dx == 0) {
      for (int i = 2; i < length; i++) {
        if (coordinates[i][0] != coordinates[0][0]) return false;
      }

      return true;
    }

    double slope = dy / dx;

    for (int i = 2; i < length; i++) {
      double nextDx = coordinates[i][0] - coordinates[0][0];
      double nextDy = coordinates[i][1] - coordinates[0][1];

      if (nextDx == 0 || nextDy == 0) return false;
      if (nextDy / nextDx != slope) return false;
    }

    return true;
  }
} solution;

int main() {
  // vector<vector<int>> coordinates = {{1, 2}, {2, 3}, {3, 4},
  //                                    {4, 5}, {5, 6}, {6, 7}};
  vector<vector<int>> coordinates = {{1, 1}, {2, 2}, {3, 4},
                                     {4, 5}, {5, 6}, {7, 7}};
  // vector<vector<int>> coordinates = {
  //     {-9, 4},  {-10, -7}, {11, 4},   {-13, -13}, {-7, -1},
  //     {-8, -4}, {-13, -3}, {10, -14}, {13, 6},    {-2, -4},
  //     {-6, 5},  {-5, -2},  {-8, -10}, {-10, 10}};

  cout << solution.checkStraightLine(coordinates) << endl;

  return 0;
}