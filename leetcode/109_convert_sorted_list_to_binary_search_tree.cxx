import "./TreeNode.cxx";

/**
 * TODO: 寫個不靠 vector 的解法吧
 */

class Solution {
 public:
  TreeNode* sortedListToBST(ListNode* head) {
    vector<ListNode*> nodes;
    ListNode* pointer = head;

    while (pointer != nullptr) {
      nodes.push_back(pointer);
      pointer = pointer->next;
    }

    return helper(nodes, 0, nodes.size());
  }

  TreeNode* helper(vector<ListNode*>& nodes, int begin, int end) {
    if (begin >= end) return nullptr;

    int mid = (begin + end) / 2;

    TreeNode* node = new TreeNode(nodes[mid]->val);

    node->left = helper(nodes, begin, mid);
    node->right = helper(nodes, mid + 1, end);
    return node;
  }
};