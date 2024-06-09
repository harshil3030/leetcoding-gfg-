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
    
    void flatten(TreeNode* root) {
        
        if (!root) return;
        TreeNode* left = root -> left;
        TreeNode* right = root -> right;
        root -> left = nullptr;
        root -> right = left;
        TreeNode* edge = root;
        while (edge -> right != nullptr) edge = edge -> right;
        edge -> right = right;
        flatten(root -> right);
        
    }
    
    /*
        1              1                  1
      /  \              \                  \
     2    5              2                   2
    / \    \            /  \                  \
   3   4    6           3   4                  3
                             \                  \
                              5                  4
                               \                  ....
                                6
    */
    
};