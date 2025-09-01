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
    int num_goodNodes = 0;
    void dfs_helper(TreeNode* node, int max_pathsum){
        if(node->val==max_pathsum)
            num_goodNodes++;
        if(node->left)
            dfs_helper(node->left, max(node->left->val, max_pathsum));
        if(node->right)
            dfs_helper(node->right, max(node->right->val, max_pathsum));
        return;
    }
public:
    int goodNodes(TreeNode* root) {
        if(root)
            dfs_helper(root, root->val);
        return num_goodNodes;
    }
};