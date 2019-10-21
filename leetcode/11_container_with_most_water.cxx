#include <iostream>
#include <vector>
using namespace std;

// 很酷的逼近法
// https://leetcode.wang/leetCode-11-Container-With-Most-Water.html

int min(int x, int y) { return x < y ? x : y; }

class Solution {
 public:
  int maxArea(vector<int> &height) {
    int result = 0;
    int width = height.size() - 1;
    vector<int>::iterator begin = height.begin();
    vector<int>::iterator end = height.end() - 1;

    while (begin != end) {
      int volume = min(*begin, *end) * width;

      if (volume > result) result = volume;

      if (*begin > *end) {
        end--;
        width--;
        continue;
      }

      begin++;
      width--;
    }

    return result;
  }
} solution;

int main() {
  vector<int> target = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  cout << solution.maxArea(target) << endl;

  return 0;
}