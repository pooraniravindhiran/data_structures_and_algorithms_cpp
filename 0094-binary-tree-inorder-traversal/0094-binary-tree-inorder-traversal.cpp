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


 //Morris traversal but modifies tree- O(n), O(1)
class Solution {
    vector<int> result;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr=root;
        TreeNode* last;
        
        while(curr!=NULL){
            if(curr->left==NULL){
                result.push_back(curr->val);
                curr= curr->right;
            }
            else{
                last= curr->left;
                while(last->right!=NULL)
                    last= last->right;
                last->right= curr;
                TreeNode* temp= curr;
                curr= curr->left;
                temp->left= NULL;
            }

        }
        return result;
    }
};

// class Solution {
//     vector<int> result;
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         stack<TreeNode*> s;
//         TreeNode* curr= root;
//         while(curr!=NULL or !s.empty()){
//             if(curr!=NULL){
//                 s.push(curr);
//                 curr= curr->left;
//             }
//             else{
//                 TreeNode* top= s.top();
//                 s.pop();
//                 result.push_back(top->val);
//                 curr= top->right;
//             }
//         }
//         return result;
//     }
// };
// class Solution {
//     vector<int> result;
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         if(root==NULL)
//             return result;
//         stack<TreeNode*> s;
//         TreeNode* curr= root;
//         while(curr!=NULL or !s.empty()){
//             while(curr!=NULL){
//                 s.push(curr);
//                 curr= curr->left;
//             }
//             curr= s.top();
//             s.pop();
//             result.push_back(curr->val);
//             curr= curr->right;
//         }
//         return result;
//     }
// };