// TC- O(n)
// SC- O(n)

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
class Solution {
private:
    bool isInBetween(TreeNode* node, long min_val, long max_val){
        if(!node)
            return true;
        if(node->val>max_val or node->val<min_val)
            return false;
        return (isInBetween(node->left, min_val, node->val-1) and isInBetween(node->right, node->val+1, max_val));
    }
public:
    bool isValidBST(TreeNode* root) {
        return isInBetween(root, INT_MIN, INT_MAX);
    }
};