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
    TreeNode* build(vector<int> &preorder, vector<int> inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) {
            return nullptr;
        }
        
        int curr = preorder[preorder.size() - 1];
        TreeNode* root = new TreeNode(curr);
        preorder.pop_back();
        
        vector<int> inleft;
        vector<int> inright;
        
        int ind = -1;
        for(int i = 0; i < inorder.size(); i++) {
            if (inorder[i] != curr) {
                inleft.push_back(inorder[i]);
            } else {
                ind = i+1;
                break;
            }
        }
        
        for(int i = ind; i < inorder.size(); i++) {
            inright.push_back(inorder[i]);
        }
        
        root -> left = build(preorder, inleft);
        root -> right = build(preorder, inright);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        reverse(preorder.begin(), preorder.end());
        return build(preorder, inorder);
    }
    /*
        here, preorder should be the pass by reference, can you tell me why ? 
        because when it go with creating the left subtree the value of creating nodes as root should be disappear before passing 
        to right subtree
    
    */
    
};