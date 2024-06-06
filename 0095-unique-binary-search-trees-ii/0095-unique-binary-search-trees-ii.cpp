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
    
    vector<TreeNode*> gen(int start, int end, map<pair<int, int>, vector<TreeNode*>> &memo) {
        
        vector<TreeNode*> res;
        
        if (start > end) {
            TreeNode* root = nullptr;
            res.push_back(root);
            return res;
        }
        
        if(memo.count({start, end})) {
            return memo[{start, end}];
        }
        
        for(int i = start; i <= end; i++) {
            
            vector<TreeNode*> fromleft = gen(start, i-1, memo);
            vector<TreeNode*> fromright = gen(i + 1, end, memo);
            for(auto &left : fromleft) {
                for(auto &right : fromright) {
                    TreeNode* root = new TreeNode(i);
                    root -> left = left;
                    root -> right = right;
                    res.push_back(root);
                }
            }
        }
        memo[{start, end}] = res;
        return res;
    }
    
    
    
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode*>> memo;
        return gen(1, n, memo);
    }
};