#include <vector>
using namespace std;

class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& arr) {
    int left = 0;
    int right = arr.size();
    return peakIndexInMountainArray(arr, left, right);
  }

  int peakIndexInMountainArray(vector<int>& arr, int& left, int& right) {
    int i = (left + right) / 2;
    bool isLeftLower = arr[i - 1] < arr[i];
    bool isRightLower = arr[i] > arr[i + 1];

    if (isLeftLower && isRightLower) return i;
    if (isLeftLower) return peakIndexInMountainArray(arr, i, right);

    return peakIndexInMountainArray(arr, left, ++i);
  }
};