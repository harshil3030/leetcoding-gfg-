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
public:
    
    TreeNode* fun(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        
        TreeNode* left = fun(root -> left, p, q);
        TreeNode* right = fun(root -> right, p, q);
        
        if (left == nullptr) return right;
        if (right == nullptr) return left;
        else return root;
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return fun(root, p, q);
    }
    
    /*
        let's assume the tree with two sided child p,q 
        
        once you got the p from left subtree, you will fetch that node
        once you got the q from right subtree you will fetch that node 
        once you got both from left and right that's the root or the lowestcommenancester for both p and the q
        
        
        how to do that ? 
        
        if the current node is p or q or root is null return it ....
        
        
        ask for left subtree to provide it
        ask for right subtree to provide it
        
        if one of that is nullptr provide second one 
        else provide it self (root)
        
        now assume both the ancestors are in the row ... 
        
            . ... . 
           / 
          2   p = 2, q = 1;
         /    now once left tree find the 2 it will return it.
        3     and at the end it will not find the second one which is q and return 2 till the last and become the ancestor
       /
      1
        
    
    */
};