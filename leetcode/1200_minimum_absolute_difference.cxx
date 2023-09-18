#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    int size = arr.size();
    vector<vector<int>> result;
    int absValue = INT_MAX;

    for (int i = 1; i < size; i++) {
      if (arr[i] - arr[i - 1] > absValue) continue;
      if (arr[i] - arr[i - 1] < absValue) {
        result.clear();
        absValue = arr[i] - arr[i - 1];
      }

      result.push_back({arr[i - 1], arr[i]});
    }

    return result;
  }
};