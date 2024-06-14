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
    int findHeight(TreeNode* root) {
        if (!root) return 0;
        
        int leftSide = 1 + findHeight(root -> left);
        int rightSide = 1 + findHeight(root -> right);
        
        return max(leftSide, rightSide);
    }
    
    void fill(vector<vector<string>> &ans, TreeNode* root, int start, int end, int level) {
        
        if (!root) return;
        
        int mid = (start + end) / 2;
        ans[level][mid] = to_string(root -> val);
        
        fill(ans, root -> left, start, mid - 1, level + 1);
        fill(ans, root -> right, mid + 1, end, level + 1);
    }
    
    
    vector<vector<string>> printTree(TreeNode* root) {
        int height = findHeight(root);
        
        vector<vector<string>> ans(height, vector<string> ((1ll << height)  - 1));
        fill(ans, root, 0, (1ll << height) - 2 ,0);
        
        return ans;
    }
    /*
        again amazing problem first have to find the height
        according to it create the vector<Vector<string>> ans
        and then the final step is to fill it using devide and conquer
    
    */
};