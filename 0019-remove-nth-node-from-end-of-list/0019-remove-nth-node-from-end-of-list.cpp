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
    ListNode* fun(ListNode* head, int n, int &cnt, bool &ok) {
        if(head -> next != nullptr) {
            fun(head -> next, n, cnt, ok);
            cnt++;
        }     
        
        if (cnt == n) {
            ok = true;
            head -> next = head -> next -> next;
        }
        return head;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0; bool ok = false;
        ListNode* curr =  fun(head, n, cnt, ok);
        if (!ok) {
            curr = curr -> next;
        }
        return curr;
    }
};