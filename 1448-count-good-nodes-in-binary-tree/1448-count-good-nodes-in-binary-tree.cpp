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
    int num_goodNodes = 0;
    void dfs_helper(TreeNode* node, int max_pathsum_sofar){
        if(node->val>=max_pathsum_sofar)
            num_goodNodes++;
        if(node->left)
            dfs_helper(node->left, max(node->val, max_pathsum_sofar));
        if(node->right)
            dfs_helper(node->right, max(node->val, max_pathsum_sofar));
        return;
    }
public:
    int goodNodes(TreeNode* root) {
        if(root)
            dfs_helper(root, INT_MIN);
        return num_goodNodes;
    }
};