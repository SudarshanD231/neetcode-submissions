class MinStack {
    struct Node {
        int val, minSoFar;
        Node* next;
        Node(int v, int m, Node* n) : val(v), minSoFar(m), next(n) {}
    };
    Node* head = nullptr;

public:
    MinStack() {}

    void push(int val) {
        int m = head ? min(val, head->minSoFar) : val;
        head = new Node(val, m, head);
    }

    void pop() {
        Node* old = head;
        head = head->next;
        delete old;
    }

    int top()    { return head->val; }
    int getMin() { return head->minSoFar; }
};