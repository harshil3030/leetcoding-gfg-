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
    
    ListNode* mergell(ListNode* left, ListNode* right) {
        
        ListNode* dummy = new ListNode(-1);
        ListNode* dummyh = dummy;
        while(left != nullptr && right != nullptr) {
            if (left -> val < right -> val) {
                dummy -> next = left;
                left = left -> next;
            } else {
                dummy -> next = right;
                right = right -> next;
            }
            dummy = dummy -> next;
        }
        
        if(left != nullptr) {
            dummy -> next = left;
        }
        
        if(right != nullptr) {
            dummy -> next = right;
        }
        
        return dummyh -> next;
    }
    
    ListNode* findmid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast  = head -> next;
        
        while(fast != nullptr && fast -> next != nullptr) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }
        
    ListNode* merge(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;
        
        ListNode* left = head;
        ListNode* mid = findmid(head);
        ListNode* right = mid -> next;
        mid -> next = nullptr;
        
        
        ListNode* ff = merge(left);
        ListNode* ss = merge(right);
        
        return mergell(ff, ss);
        
    }
    
    ListNode* sortList(ListNode* head) { 
       return merge(head);
       
    }
};