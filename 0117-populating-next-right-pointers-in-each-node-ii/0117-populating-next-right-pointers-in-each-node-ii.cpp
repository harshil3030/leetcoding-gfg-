/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* pre = nullptr;           // previous in lower level
        Node* head = nullptr;          // left most in lower level
        Node* curr = root;             // current in -> [upper level]
        
        while (curr != nullptr) {
            while (curr != nullptr) {
                if (curr -> left) {
                    if (head == nullptr) {
                        head = curr -> left;
                    }    
                    if (pre == nullptr) {
                        pre = curr -> left;
                    } else {
                        pre -> next = curr -> left;
                        pre = pre -> next;
                    }
                }
                
                if (curr -> right) {
                    if (head == nullptr) {
                        head = curr -> right;
                    }
                    if (pre == nullptr) {
                        pre = curr -> right;
                    } else {
                        pre -> next = curr -> right;
                        pre = pre -> next;
                    }
                }
                curr = curr -> next;
            }
            
            pre = nullptr;
            curr = head;
            head = nullptr;
            
        }
        return root;
    }
    /*
        how can you contain this problem and how to resolve the problem for the same 
    */
};