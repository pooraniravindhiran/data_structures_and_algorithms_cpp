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
    bool isIdentical(TreeNode* node1, TreeNode* node2){
        if(node1==NULL and node2==NULL)
            return true;
        else if((node1==NULL or node2==NULL) or (node1->val!=node2->val))
            return false;
        return (isIdentical(node1->left, node2->left)and isIdentical(node1->right, node2->right));
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL)
            return false;
        if(isIdentical(root, subRoot))
            return true;
        return (isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot));
    }
};