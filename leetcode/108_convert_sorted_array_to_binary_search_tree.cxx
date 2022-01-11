#include <iostream>
#include <vector>

#include "./TreeNode.cxx"

using namespace std;

class Solution {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    int begin = 0;
    int end = nums.size();

    return helper(nums, begin, end);
  }

  TreeNode* helper(vector<int>& nums, int& begin, int& end) {
    if (begin >= end) return NULL;

    int mid = (begin + end) / 2;

    TreeNode* node = new TreeNode(nums[mid]);

    node->left = helper(nums, begin, mid);
    mid++;
    node->right = helper(nums, mid, end);

    return node;
  }
};