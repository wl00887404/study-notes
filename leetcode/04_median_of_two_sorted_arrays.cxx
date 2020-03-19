#include <iostream>
#include <vector>
using namespace std;

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

class Solution {
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

int main() {
  vector<int> nums1 = {1, 3};
  vector<int> nums2 = {2};

  // vector<int> nums1 = {1, 2};
  // vector<int> nums2 = {3, 4};

  cout << solution.findMedianSortedArrays(nums1, nums2) << endl;

  return 0;
};
