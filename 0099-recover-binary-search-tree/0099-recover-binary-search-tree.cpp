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
    void fun(TreeNode* root, TreeNode* &pre, TreeNode* &first, TreeNode* &second) {
        if (!root) return;
        fun(root -> left , pre, first, second);
        
        if (pre != nullptr) {
            if (root -> val < pre -> val) {
                if (!first) {
                    first = pre;
                } 
                second = root;
            }
        }
        pre = root;
        fun(root -> right, pre, first, second);
    }
    
    
    void recoverTree(TreeNode* root) {
        TreeNode* pre = nullptr;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        fun(root, pre, first, second);
        swap(first -> val, second -> val);
    }
    
    /*
        it will take some time to understand the actual algo
        it's start with the realization that inorder traversal will help us to find the sick nodes
        
        how we will find it ? 
        how it looks like when we figure out 
        
        1.. 2.. 3.. sorted and then .. 8.. 5.. 
                                       |   |
                                       pre root(curr)
                                       
                                       pre -> val > curr -> val ... you get the first element which is wrong
       how you will get the second ? 
       6.. 7.. 4..
           |    |
           bruh, the same situation
           pre -> val > root -> val
           
           but the imposter is root this time 
           it should be bigger then previous other wise it should come before then 7, here 7 is not problem because we already              get the the first imposter which was bigger then it's next one 
           
      what if they are swaped adjucent ? 
      
      if this happens then 
      we have to assume the first time
        pre -> val > root -> val condition happens 
        
     the root is the second imposter
     
     so don't use if condition which tells you can take second element only if first element found or this condition is happened
     before just take out the second element from the root if this condition heppens 
     
    the last  pre, first and the second should be passed with address 
        why pre ? 
        
        assume tree is going towards left ..
             3 -> pre = null
            2 -> pre = null
           1 -> pre = null   even in return time 2 -> pre = null without address because we cannot define it while calling the 2 
        
        
        after using passbyaddress
           3 -> pre = null
          2 -> pre = null
         1 -> pre = null   at return time  2 -> pre = 1
                                           3 -> pre = 2
    */
    
};