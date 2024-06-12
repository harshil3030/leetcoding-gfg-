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
    int cnt = 0;
    
    void fun(TreeNode* root, int target, vector<long long> tmp) {
        
        if (!root) return;
        
        long long currval = root -> val;
        if (currval == target) cnt++;
        
        for(int i = (int)tmp.size() - 1; i >= 0; i--) {
            currval += tmp[i];
            if (currval == target) cnt++;
        }
        
        tmp.push_back(root -> val);
        fun(root -> left, target, tmp);
        fun(root -> right, target, tmp);
    }
     
    
    int pathSum(TreeNode* root, int targetSum) {
        vector<long long> tmp;
        fun(root, targetSum, tmp);
        return cnt;
    }
    
    
};