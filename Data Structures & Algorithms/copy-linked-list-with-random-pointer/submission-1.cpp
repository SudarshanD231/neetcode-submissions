/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // HashMap: old node → new node
        unordered_map<Node*, Node*> oldToCopy;

        // First pass: create all the new nodes
        Node* cur = head;
        while (cur) {
            oldToCopy[cur] = new Node(cur->val);
            cur = cur->next;
        }

        // Second pass: assign next and random pointers
        cur = head;
        while (cur) {
            Node* copy = oldToCopy[cur];
            copy->next = oldToCopy[cur->next];       // works even if cur->next is NULL
            copy->random = oldToCopy[cur->random];   // works even if cur->random is NULL
            cur = cur->next;
        }

        return oldToCopy[head];
    }
};