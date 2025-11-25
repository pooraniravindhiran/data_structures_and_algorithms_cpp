// TC- O(n)
// SC - O(n)

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
    int cam_count = 0;

    int postorder_helper(TreeNode* node){
        if(!node)
            return 2;
        
        int left_state = postorder_helper(node->left);
        int right_state = postorder_helper(node->right);
        
        if(left_state==0 or right_state==0){
            // need a camera, so place it
            cam_count++;
            return 1;
        }

        if(left_state==1 or right_state==1){
            // is covered
            return 2;
        }

        return 0;      
    }
public:
    int minCameraCover(TreeNode* root) {
        // top down or bottom up approach? second because you would otherwise not know the optimal placement- so we analyze children first and then the current node- postorder
        // possible states - 0 (needs coverage), 1 (is covered and has a camera), 2 (is covered but no camera)

        if(postorder_helper(root)==0)
            cam_count++;

        return cam_count;
    }
};