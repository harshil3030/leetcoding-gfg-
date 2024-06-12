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
    
    
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            TreeNode* pre = root;

            int valp = p -> val;
            int valq = q -> val;
            if (valq < valp) swap(valp, valq);

            while (true) {
                if (pre -> val >= valp && pre -> val <= valq) return pre;
                else if (pre -> val <= valp) pre = pre -> right;
                else if (pre -> val >= valq) pre = pre -> left;
            }

            return nullptr;

        /*
            finding the lowestCommonAncestor in the recursive solution is provided for the binary tree
            let;s do iteratively for binary search tree 
            with o(1) space complexity
        */
        }
};