/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ff = headA;
        ListNode* ss = headB;
        
        while(ff != ss) {
            ff = ff == nullptr ? headB : ff -> next;
            ss = ss == nullptr ? headA : ss -> next;
        }
        
        return ff;
    }
};