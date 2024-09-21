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
    bool hasCycle(ListNode *head) {
        ListNode* sl = head;
        ListNode* fa = head;
        bool ok = false;
        while(fa != nullptr && fa -> next != nullptr) {
            sl = sl -> next;
            fa = fa -> next -> next;
            
            if (sl == fa) {
                ok = true;
                break;
            }
        }
        
        if(ok) return true;
        return false;
    }
};