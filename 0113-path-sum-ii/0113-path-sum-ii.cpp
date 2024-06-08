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
    vector<vector<int>> res;
    void cal(TreeNode* root, int tar, int curr, vector<int> tmp) {
        if (!root) {
            return;
        }
        
        tmp.push_back(root -> val);
        curr += (root -> val);
        if (root -> left == nullptr && root -> right == nullptr) {
            if (curr == tar) {
                res.push_back(tmp);
            }
            return;
        }
        cal(root -> left, tar, curr, tmp);
        cal(root -> right, tar, curr, tmp);
        
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> tmp;
        cal(root, targetSum, 0, tmp);
        return res;
    }
};