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
    void fun(TreeNode* root, int &curr) {
        if (!root) return;
        
        fun(root -> right, curr);
        
        curr += root -> val;
        root -> val = curr;
        
        fun(root -> left, curr);
        
    
    }
    
    
    TreeNode* convertBST(TreeNode* root) {
        int tmp = 0;
        fun(root, tmp);
        return root;
    }
};