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
    
    void fun(TreeNode* root, int target, vector<long long> &tmp) {
        
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
        tmp.pop_back();
    }
     
//     void secondway(TreeNode* root, int target, long long curr, map<long long, int> &mp) {
//         if (!root) return;
//         curr += root -> val;
        
//         cnt += mp[{curr - target}];
//         mp[curr]++;
        
//         secondway(root -> left, target, curr, mp);
//         secondway(root -> right, target, curr, mp);
        
//         mp[curr]--;
        
//     }
    
    int pathSum(TreeNode* root, int targetSum) {
        vector<long long> tmp;
        fun(root, targetSum, tmp);
        // map<long long ,int> mp;
        // mp[0] = 1;
        // secondway(root, targetSum,0,mp);
        
        return cnt;
    }
    
    /*
        yup this works but there is one more way using the map it may require bit less space 
        
        curr += root -> val
        mp[curr - tar] != mp.end
            how many of them have to provide
        
        mp[curr]++;
        
        left
        right
        
        mp[curr]--;
        
        
        
    */
    
};