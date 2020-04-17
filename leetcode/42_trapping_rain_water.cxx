#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * 遇到更高的牆
 * 就會形成一個坑
 * 左邊過去 右邊回來
*/


class Solution {
 public:
  int trap(vector<int>& height) { return trap(height, 0); }
  int trap(vector<int>& height, int i) {
    int length = height.size();

    if (length - i <= 2) return 0;

    // skip climbing up
    while (i < length - 1 && height[i] <= height[i + 1]) i++;

    if (i == length - 1) return 0;

    int result = 0;
    int begin = i;

    i++;

    while (true) {
      if (i == length) {
        reverse(height.begin() + begin, height.end());

        return trap(height, begin);
      }

      if (height[i] >= height[begin]) break;

      result -= height[i];
      i++;
    };

    result += height[begin] * (i - begin - 1);

    return result + trap(height, i);
  }
} solution;

int main() {
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  // vector<int> height = {8, 0, 1, 2, 1, 0, 8, 9, 8, 8, 9};

  cout << solution.trap(height) << endl;

  return 0;
}