#include <iostream>
#include <vector>
using namespace std;

/**
 * 不用 class 跑分不會比較高
 * 哭哭哭哭哭
 * class 版本的程式碼比較好看
 * commit: 3a64815
 */


class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    bool isOdd = (nums1.size() + nums2.size()) % 2;
    int beforeCenter = (nums1.size() + nums2.size() + isOdd) / 2 - 1;
    int median1;
    int median2;

    vector<int>::iterator begin1 = nums1.begin();
    vector<int>::iterator end1 = nums1.end();
    vector<int>::iterator begin2 = nums2.begin();
    vector<int>::iterator end2 = nums2.end();

    while (beforeCenter--) {
      if (begin1 == end1) {
        begin2++;
      } else if (begin2 == end2) {
        begin1++;
      } else if (*begin1 > *begin2) {
        begin2++;
      } else {
        begin1++;
      }
    }

    if (begin1 == end1) {
      median1 = *(begin2++);
    } else if (begin2 == end2) {
      median1 = *(begin1++);
    } else if (*begin1 > *begin2) {
      median1 = *(begin2++);
    } else {
      median1 = *(begin1++);
    }

    if (isOdd) return median1;

    if (begin1 == end1) {
      median2 = *(begin2);
    } else if (begin2 == end2) {
      median2 = *(begin1);
    } else if (*begin1 > *begin2) {
      median2 = *begin2;
    } else {
      median2 = *begin1;
    }

    return (median1 + median2) / 2.0;
  }
} solution;

int main() {
  vector<int> nums1 = {1, 3};
  vector<int> nums2 = {2};

  // vector<int> nums1 = {1, 2};
  // vector<int> nums2 = {3, 4};

  cout << solution.findMedianSortedArrays(nums1, nums2) << endl;

  return 0;
};
