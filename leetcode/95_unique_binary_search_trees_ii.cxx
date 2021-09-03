#include <iostream>
#include <vector>

#include "./TreeNode.cxx"
using namespace std;

/**
 * 1 => [1]
 * 2 => [1, 2] | [1, 2]
 *       ^  >     <  ^
 * 3 => [1, 2, 3] | [1, 2, 3] | [1, 2, 3]
 *       ^  >  >     <  ^  >     <  <  ^
 * 4 => [1, 2, 3, 4] | [1, 2, 3, 4] | [1, 2, 3, 4] | [1, 2, 3, 4]
 *       ^  >  >  >     <  ^  >  >     <  <  ^  >     <  <  <  ^
 *
 * 1
 * 1 + 1
 * 2 + 1 + 2
 * 3 + (1 * 2) + (2 * 1) + 3
 * 4 + (1 * 3) + (2 * 2) + (3 * 1) + 4
 */

class Solution {
 public:
  vector<TreeNode*> generateTrees(int n) { return helper(1, n + 1); }

  // start 為 included
  // end 為 excluded
  vector<TreeNode*> helper(int start, int end) {
    if (start >= end) return {NULL};

    vector<TreeNode*> result;
    for (int i = start; i < end; i++) {
      vector<TreeNode*> leftResult = helper(start, i);
      vector<TreeNode*> rightResult = helper(i + 1, end);

      for (int j = 0; j < leftResult.size(); j++) {
        for (int k = 0; k < rightResult.size(); k++) {
          result.push_back(new TreeNode(i, leftResult[j], rightResult[k]));
        }
      }
    }

    return result;
  }
};