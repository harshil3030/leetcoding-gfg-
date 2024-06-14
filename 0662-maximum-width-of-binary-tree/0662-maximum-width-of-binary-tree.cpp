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
    
    
    int widthOfBinaryTree(TreeNode* root) {
        vector<pair<TreeNode*, long long>> q;
        q.push_back({root, 1});
        
        long long mx = 1;
        while (!q.empty()) {
            int size = q.size();
            pair<TreeNode*, long long> curr = q[0];
            mx = max(mx, q.back().second - q[0].second + 1);
            
            
            vector<pair<TreeNode*, long long>> nxt;
            
            for(int i = 0; i < size; i++) {
                pair<TreeNode*, long long> front = q[i];
                
                if (front.first -> left) nxt.push_back({front.first -> left, (front.second - curr.second)*2 + 1});
                if (front.first -> right) nxt.push_back({front.first -> right, (front.second - curr.second + 1) * 2});
            }
            q = nxt;
        }
        
        return mx;
    }
    
    /*
        it could be quite complecated but 
        you can do it with proper maths and using vector so we can access both side
    
    */
};