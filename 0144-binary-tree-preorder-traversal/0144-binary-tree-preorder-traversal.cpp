// iterative
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
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(curr!=NULL or !st.empty()){
            if(curr!=NULL){
                preorder.push_back(curr->val);
                st.push(curr);
                curr = curr->left;
            }
            else{
                curr = st.top();
                st.pop();
                curr = curr->right;
            }

        }
        return preorder;
    }
};

// // recursive
// // TC- O(n)
// // SC- O(n)

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// private:
//     void helper(TreeNode* node, vector<int>& preorder){
//         if(node==NULL)
//             return;
//         preorder.push_back(node->val);
//         helper(node->left, preorder);
//         helper(node->right, preorder);
//     }
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> preorder;
//         helper(root, preorder);
//         return preorder;
//     }
// };