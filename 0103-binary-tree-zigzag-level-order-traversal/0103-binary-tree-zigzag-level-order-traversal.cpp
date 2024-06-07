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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int cnt = 0;
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        
        if (!root) {
            return res;
        }
                
        while (!q.empty()) {
            int size = q.size();
            vector<int> include;
            for(int i = 0; i < size; i++) {
                TreeNode* top = q.front();
                q.pop();
                include.push_back(top -> val);
                if (top -> left != nullptr) {
                    q.push(top -> left);
                }
                
                if (top -> right != nullptr) {
                    q.push(top -> right);
                }
            }
            if (cnt % 2 == 0) {
                res.push_back(include);
            } else {
                reverse(include.begin(), include.end());
                res.push_back(include);
            }
            cnt++;
        }
        
        return res;
    }
};