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
    map<int, int> mp;
    
    int fun(TreeNode* root) {
        if (!root) return 0;
         
        int leftsum = fun(root -> left);
        int rightsum = fun(root -> right);
        
        mp[root -> val + leftsum + rightsum]++;
        return root -> val + leftsum + rightsum;
    }
    
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int tmp = fun(root);    
        
        int mx = 0;
        for(auto &x : mp) {
            mx = max(mx, x.second);
        }
        
        vector<int> ans;
        for(auto &x : mp) {
            if (x.second == mx) {
                ans.push_back(x.first);
            }
        }
        
        return ans;
    }
};