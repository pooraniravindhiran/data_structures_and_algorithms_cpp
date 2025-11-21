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
// SC- O(h) - where h is height of tree. worst case it is n, and best case it is logn

class Solution {
private:
    int rbfs(TreeNode* node, int level){
        if(!node)
            return level-1;
        return max(rbfs(node->left, level+1), rbfs(node->right, level+1));
    }
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        return rbfs(root, 1);
    }
};