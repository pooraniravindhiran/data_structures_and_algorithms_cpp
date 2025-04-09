/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* LCA;
    bool subtreeContainsOneTarget(TreeNode* root, TreeNode* p, TreeNode* q){
        if (root==NULL)
            return false;
        int mid = (root==p or root==q) ? 1:0;
        int left = (subtreeContainsOneTarget(root->left, p, q)) ? 1:0;
        int right = (subtreeContainsOneTarget(root->right, p, q)) ? 1:0;
        if((mid+left+right)==2)
            LCA = root;
        return ((mid+left+right)>0);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        subtreeContainsOneTarget(root, p, q);
        return LCA;
    }
};

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         // Base case: If the root is null, return null
//         if (root == nullptr) {
//             return nullptr;
//         }

//         // Value of the current node (root)
//         int parentVal = root->val;

//         // Value of p
//         int pVal = p->val;

//         // Value of q
//         int qVal = q->val;

//         if (pVal > parentVal && qVal > parentVal) {
//             // Both p and q are greater than parent, search in the right subtree
//             return lowestCommonAncestor(root->right, p, q);
//         } else if (pVal < parentVal && qVal < parentVal) {
//             // Both p and q are smaller than parent, search in the left subtree
//             return lowestCommonAncestor(root->left, p, q);
//         } else {
//             // We found the split point, the LCA
//             return root;
//         }
//     }
// };
