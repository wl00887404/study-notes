#include <iostream>
#include <vector>
using namespace std;

/**
 * TODO: 研究 model answer
 */

class MergedVector {
 private:
  vector<int>::iterator begin1;
  vector<int>::iterator end1;
  vector<int>::iterator begin2;
  vector<int>::iterator end2;

 public:
  MergedVector(vector<int>& nums1, vector<int>& nums2) {
    this->begin1 = nums1.begin();
    this->end1 = nums1.end();
    this->begin2 = nums2.begin();
    this->end2 = nums2.end();
  }

  int next() {
    if (this->begin1 == this->end1) return *(this->begin2++);
    if (this->begin2 == this->end2) return *(this->begin1++);

    return *this->begin1 > *this->begin2 ? *(this->begin2++)
                                         : *(this->begin1++);
  };
};

class OldSolution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    bool isOdd = (nums1.size() + nums2.size()) % 2;
    int beforeCenter = (nums1.size() + nums2.size() + isOdd) / 2 - 1;
    MergedVector* mergedVector = new MergedVector(nums1, nums2);

    while (beforeCenter--) mergedVector->next();

    if (isOdd) return mergedVector->next();

    return (mergedVector->next() + mergedVector->next()) / 2.0;
  }
} solution;

/**
 * 2023/09/21 的每日
 * 完全不記得自己寫過，上次寫是 4 年前
 * 而且題目要求要 O(log(m + n))
 * 我這個寫法根本就沒有吧，這個寫法是 O((m + n) / 2)
 */

/**
 * 應該是可以用 nums1 nums2 的中位數來縮小範圍才對
 *
 * 如果我拿 num2 的中位數去 nums1 裡找
 * 可以 O(log m) 找到插入位置，以預估合併後的中位數狀況？
 *
 * 如果 num1 的中位數 > num2 最大值
 * 所有 num2 的元素都會插在 num1 左側，中位數會往左移動，反之亦然
 * 如果介於 num2 最小值與最大值之間，二分搜可以抓到插入情況
 *
 * nums1 = [1, 100, 200, 300, 400], median = 200
 * nums2 = [2, 3, 4, 5]
 * 合併之後 nums2 都會插在 200 左側
 * 200 是 nums1[2] ，合併後變成 nums3[6] ，新的中位數應該是 nums3[4]
 *
 * 欸不對，我可以把 nums[1] 的元素丟進去 nums2 二分搜
 * 就能直接確定它是 nums3 的第幾位
 */

/**
 * 換了一個寫法
 * 直接把 nums1 的元素在 nums2 中二分搜，嘗試找到 median
 * 如果找不到就反過來再做一次
 */
class Solution {
 public:
  int m;
  int n;

  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    m = nums1.size();
    n = nums2.size();

    if (m == 0) return getMedian(nums2, n);
    if (n == 0) return getMedian(nums1, m);

    int targetIndex = (m + n) / 2;
    bool isTwo = (m + n) % 2 == 0;
    double result = 0;

    result += findTarget(nums1, nums2, targetIndex);
    if (isTwo) {
      result += findTarget(nums1, nums2, targetIndex - 1);
      result /= 2;
    }

    return result;
  }

  int findTarget(vector<int>& nums1, vector<int>& nums2, int targetIndex) {
    int left = 0;
    int right = m;

    while (left < right) {
      int mid = (left + right) / 2;
      int minRealIndex = mid + binarySearch(nums2, n, nums1[mid], true);
      int maxRealIndex = mid + binarySearch(nums2, n, nums1[mid], false);

      if (minRealIndex <= targetIndex && targetIndex <= maxRealIndex) {
        return nums1[mid];
      }

      if (minRealIndex > targetIndex) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    left = 0;
    right = n;
    while (left < right) {
      int mid = (left + right) / 2;
      int minRealIndex = mid + binarySearch(nums1, m, nums2[mid], true);
      int maxRealIndex = mid + binarySearch(nums1, m, nums2[mid], false);

      if (minRealIndex <= targetIndex && targetIndex <= maxRealIndex) {
        return nums2[mid];
      }

      if (minRealIndex > targetIndex) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    throw range_error("targetIndex out of m + n");
  }

  int binarySearch(vector<int>& nums, int right, int k, bool leftFirst = true) {
    int left = 0;

    while (left < right) {
      int mid = (left + right) / 2;

      if (nums[mid] == k) {
        // 如果一樣的話，優先往左走
        if (leftFirst) {
          right = mid;
        } else {
          left = mid + 1;
        }
      } else if (nums[mid] < k) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return left;
  }

  double getMedian(vector<int>& nums, int& size) {
    if (size % 2 == 1) return nums[size / 2];

    return ((double)nums[size / 2] + nums[size / 2 - 1]) / 2;
  }
};

int main() {
  vector<int> nums1 = {1, 3};
  vector<int> nums2 = {2};

  // vector<int> nums1 = {1, 2};
  // vector<int> nums2 = {3, 4};

  cout << solution.findMedianSortedArrays(nums1, nums2) << endl;

  return 0;
};
