#include <queue>
#include <vector>

#include "./TreeNode.cxx"
using namespace std;

class Solution {
 public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if (root == NULL) return {};

    queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>> result;

    while (!q.empty()) {
      result.insert(result.begin(), vector<int>());
      int length = q.size();
      while (length--) {
        result[0].push_back(q.front()->val);
        if (q.front()->left) q.push(q.front()->left);
        if (q.front()->right) q.push(q.front()->right);
        q.pop();
      }
    }

    return result;
  }
};