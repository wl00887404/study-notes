#include <iostream>
#include <climits>
#include <queue>
#include "./TreeNode.cxx"

using namespace std;

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int max = INT_MIN;
        int result = 0;
        int level = 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            int sum = 0;
            level++;
            while(size--){
                TreeNode* node = q.front();
                sum += node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                q.pop();
            }

            if(sum > max) {
                max = sum;
                result = level;
            }
        }

        return result;
    }
};