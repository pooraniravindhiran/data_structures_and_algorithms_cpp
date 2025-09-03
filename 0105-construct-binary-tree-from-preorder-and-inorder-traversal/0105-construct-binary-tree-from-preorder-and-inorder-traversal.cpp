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
    vector<int> inorder, preorder;
    int pindex;
    unordered_map<int, int> inorderIndexLookup;

    TreeNode* helper(int ileftTreeBegin, int irightTreeEnd){
        if(ileftTreeBegin>irightTreeEnd)
            return NULL;
        TreeNode* node= new TreeNode(preorder[pindex]);
        int iindex= inorderIndexLookup[node->val];
        pindex++;
        node->left= helper(ileftTreeBegin, iindex-1);
        node->right= helper(iindex+1, irightTreeEnd);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->inorder= inorder;
        this->preorder= preorder;
        pindex= 0;

        // create a lookup for finding index of given node from inorder array
        for(int i=0; i<inorder.size();i++)
            inorderIndexLookup.insert({inorder[i],i});

        // call recursive function
        return helper(0, inorder.size()-1);
    }
};