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
        if (!root) return root;
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            vector<Node*> v;
            for (int i = 0; i < size; i++) {
                Node* front = q.front();
                v.push_back(front);
                q.pop();
                
                if (front -> left != nullptr) q.push(front -> left);
                if (front -> right != nullptr) q.push(front -> right);
            }
            
            for (int i = 0; i < v.size(); i++) {
                if (i == v.size() - 1) {
                    v[i] -> next = nullptr;
                } else {
                    v[i] -> next = v[i+1];
                }
            }
        }
        
        return root;
    }
};