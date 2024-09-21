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
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        if (head == nullptr || head -> next == nullptr) return head;
        ListNode* dummy = head;
        ListNode* dummy2 = new ListNode(-1);
        
        ListNode* dummy2_h = dummy2;
        
        // ListNode* odd = head -> next;
      
        ListNode* last = dummy;  
        while(dummy != nullptr && dummy -> next != nullptr) {
            dummy2 -> next = dummy -> next;
            last = dummy;
            dummy -> next = dummy -> next -> next;
            dummy2 = dummy2 -> next;
            dummy = dummy -> next;
        }
        
        dummy2 -> next = nullptr;
        
        if(dummy != nullptr) {
           dummy -> next = dummy2_h -> next;
        } else {
            last -> next = dummy2_h -> next;
        }
            
        return head;
    }
};