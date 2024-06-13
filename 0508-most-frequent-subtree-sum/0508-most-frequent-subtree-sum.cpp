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

    
    int fun(TreeNode* root, map<int, int> &mp) {
        if (!root) return 0;
         
        int leftsum = fun(root -> left, mp);
        int rightsum = fun(root -> right, mp);
        
        mp[root -> val + leftsum + rightsum]++;
        return root -> val + leftsum + rightsum;
    }
    
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int, int> mp;
        int tmp = fun(root, mp);    
        
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