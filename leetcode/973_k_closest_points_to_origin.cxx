#include <algorithm>
#include <vector>

using namespace std;

/**
 * 其實我不是很懂這一題要幹麻耶
 * 不是 sort 完就沒事了嗎？
 */

bool comparator(vector<int>& pointer1, vector<int>& pointer2) {
  return pointer1[0] * pointer1[0] + pointer1[1] * pointer1[1] <
         pointer2[0] * pointer2[0] + pointer2[1] * pointer2[1];
}

class Solution {
 public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    sort(points.begin(), points.end(), comparator);

    return vector<vector<int>>(points.begin(), points.begin() + k);
  }
};
