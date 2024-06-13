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
    TreeNode* connect(TreeNode* root) {
        if (root -> left == nullptr) {
            return root -> right;
        } else if (root -> right == nullptr) {
            return root -> left;
        } else {
            
            TreeNode* left_most_in_right = root -> right;
            
            while (left_most_in_right -> left != nullptr) {
                left_most_in_right = left_most_in_right -> left;
            }
            
            left_most_in_right -> left = root -> left;
            return root -> right;
        }
    }
    
    
    TreeNode* deleteNode(TreeNode* root, int key) {
       
        TreeNode* tmp = root;
        if (!tmp) return tmp;
        if (tmp -> val == key) {
            return connect(tmp);
        }
        
        
        while (tmp) {
            if (tmp -> left && tmp -> left -> val == key) {
                tmp -> left = connect(tmp -> left);
                break;
            } else if (tmp -> right && tmp -> right -> val == key) {
                tmp -> right = connect(tmp -> right);
                break;
            } else if (tmp -> val < key) {
                tmp = tmp -> right;
            } else {
                tmp = tmp -> left;
            }
        }
        
        
        return root;
    }
    
    /*
        we will devide this problem in 2 different subproblem 
        
        1 is find the node 
        2 is connect the node with parent 
        
        find the parent of the node which we are needed to delete 
        if it's root it self go and find the connector 
        and return it
        
        else if it's the node with parent, go till that parent and change the child with connector 
        
        how to do that if left one is null give right one 
        if right one is null give left one
        
        if none of that are null 
            
           then we require just one value bigger element to take the position 
                which one it is ? 
                    left-most in right subtree
                        ohk take it and now what we will do ? 
                        
                        we will return root -> right (not current one which is left_most of the right subtree)
                        
                        but .... we will link left_most of right subtree's left side with root -> left
                            and that's it we removed the fucking node
                            
                            one warning as well 
                            because the tmp can we nullptr which finding the node because node may not be there to delete
                            so take tmp rather than true in while loop
    */
};