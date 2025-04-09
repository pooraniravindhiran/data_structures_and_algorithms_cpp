/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// TC- O(n)
// SC- O(n)
// Applies to all trees
// class Solution {
//     TreeNode* lca;
//     bool subTreeContainsOneTarget(TreeNode* root, TreeNode* p, TreeNode* q){
//         if(root==NULL)
//             return false;
//         int mid = (root==p or root==q) ? 1:0;
//         int left = subTreeContainsOneTarget(root->left, p, q) ? 1:0;
//         int right = subTreeContainsOneTarget(root->right, p, q) ? 1:0;
//         if(mid+left+right == 2)
//             lca = root;
//         return (mid+left+right>0);
//     }
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         subTreeContainsOneTarget(root, p, q);
//         return lca;
//     }
// };

// TC- O(n)
// SC- O(n)
// Applies to BST
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;
        int pval = p->val;
        int qval = q->val;
        if(pval<root->val and qval<root->val)
            return lowestCommonAncestor(root->left, p, q);
        else if(pval>root->val and qval>root->val)
            return lowestCommonAncestor(root->right, p, q);
        else 
            return root;
    }
};