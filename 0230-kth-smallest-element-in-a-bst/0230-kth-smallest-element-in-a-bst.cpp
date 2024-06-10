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
    int mn = 1e9;
    
    void inorder (TreeNode* root, int k, int& curr) {
        if (!root) return;
        if (root -> left) inorder(root -> left, k, curr);
        curr++;
        if (curr == k) {
            mn = root -> val;
            return;
        }
        if (root -> right) inorder(root -> right, k, curr);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int curr = 0;
        inorder(root, k, curr);
        return mn;
    }
};