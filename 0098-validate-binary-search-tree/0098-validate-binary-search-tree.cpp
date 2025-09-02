/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// TC- O(n)
// SC- O(h)

class Solution {
private:
    bool helper(TreeNode* node, long llim, long ulim){
        if(!node)
            return true;
        if(node->val>=ulim or node->val<=llim)
            return false;
        return (helper(node->left, llim, node->val) and helper(node->right, node->val, ulim));
    }
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};