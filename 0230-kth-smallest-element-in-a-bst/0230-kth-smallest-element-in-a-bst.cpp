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
    vector<int> bst;
    void inorderTraversal(TreeNode* root){
        if(root==NULL)
            return;
        inorderTraversal(root->left);
        bst.push_back(root->val);
        inorderTraversal(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        inorderTraversal(root);
        return bst[k-1];
    }
};

// Optimized Solution for Dynamic BST
// To efficiently handle frequent modifications and frequent kth smallest queries, we can enhance the BST by augmenting it with node counts:

// 1. Augmented BST with Node Counts
// Each node in the BST is augmented with a size attribute that stores the number of nodes in its subtree (including itself). This allows us to determine the rank of any node in O(log n) time.

// Augmented Node Structure
// cpp
// Copy code
// struct TreeNode {
//     int val;
//     int size; // Number of nodes in the subtree rooted at this node
//     TreeNode *left, *right;
//     TreeNode(int x) : val(x), size(1), left(nullptr), right(nullptr) {}
// };
// 2. Finding the k-th Smallest
// The augmented size field helps us determine the kth smallest element efficiently:

// Compare k with the size of the left subtree:
// If k == leftSize + 1, the current node is the kth smallest.
// If k <= leftSize, recurse into the left subtree.
// If k > leftSize + 1, recurse into the right subtree with an updated k.
// cpp
// Copy code
// TreeNode* kthSmallest(TreeNode* root, int k) {
//     int leftSize = (root->left) ? root->left->size : 0;
//     if (k == leftSize + 1) return root; // Current node is the kth smallest
//     else if (k <= leftSize) return kthSmallest(root->left, k); // Go left
//     else return kthSmallest(root->right, k - leftSize - 1); // Go right
// }
// 3. Updating the size Field on Insert/Delete
// When inserting or deleting a node, update the size field for all ancestors of the affected node. This operation is O(log n) for a balanced BST.

// Insertion:
// Recursively insert the node as usual.
// After insertion, update the size of each node on the path back to the root.
// cpp
// Copy code
// TreeNode* insert(TreeNode* root, int val) {
//     if (!root) return new TreeNode(val);
//     if (val < root->val) root->left = insert(root->left, val);
//     else root->right = insert(root->right, val);
//     root->size = 1 + getSize(root->left) + getSize(root->right); // Update size
//     return root;
// }
// Deletion:
// Recursively delete the node as usual.
// After deletion, update the size of each node on the path back to the root.
// cpp
// Copy code
// TreeNode* deleteNode(TreeNode* root, int key) {
//     if (!root) return nullptr;
//     if (key < root->val) root->left = deleteNode(root->left, key);
//     else if (key > root->val) root->right = deleteNode(root->right, key);
//     else { // Found the node to delete
//         if (!root->left) return root->right;
//         if (!root->right) return root->left;
//         TreeNode* temp = findMin(root->right);
//         root->val = temp->val;
//         root->right = deleteNode(root->right, temp->val);
//     }
//     root->size = 1 + getSize(root->left) + getSize(root->right); // Update size
//     return root;
// }
// 4. Time Complexity
// Insert/Delete: O(log n) for a balanced BST.
// kth Smallest Query: O(log n).
// This approach ensures that both modifications and queries are efficient, even when performed frequently.