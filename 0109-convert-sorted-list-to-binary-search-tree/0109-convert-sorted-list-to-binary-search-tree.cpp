/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* fun(ListNode* head) {
        if (!head) return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = nullptr;
        
        while (fast != nullptr && fast -> next != nullptr) {
            fast = fast -> next -> next;
            pre = slow;
            slow = slow -> next;
        }
        
        if (pre != nullptr) {
            pre -> next = nullptr;
        }
        
        TreeNode* root = new TreeNode(slow -> val);
        
        if (slow == head) {
            return root;
        }
        
        root -> left = fun(head);
        root -> right = fun(slow -> next);
    
        return root;
    }
    
    
    TreeNode* sortedListToBST(ListNode* head) {
        return fun(head);
    }
    
    /*
        what is the important stuff over here ? 
        
        while breaking and doint devide and conquere in the list 
        
        passint head as the parameter in function it will never be the nullptr so 
        you have to under stand that if slow point becomes the head 
        
        that means you cannot use that value to create the bst again right ? 
        
        so return the root at that time so tle don't happen and further head will not go for the left subtree
    
    */
    
};