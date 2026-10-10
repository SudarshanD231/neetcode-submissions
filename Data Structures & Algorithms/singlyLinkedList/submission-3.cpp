
#include <vector>
using namespace std;

class LinkedList {
private:
    struct Node {
        int val;
        Node* next;

        Node(int val) {
            this->val = val;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    int get(int index) {
        if (index < 0) return -1;

        Node* cur = head;

        for (int i = 0; i < index && cur != nullptr; i++) {
            cur = cur->next;
        }

        if (cur == nullptr) return -1;

        return cur->val;
    }

    void insertHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;

        if (tail == nullptr) {
            tail = node;
        }
    }

    void insertTail(int val) {
        Node* node = new Node(val);

        if (tail == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    bool remove(int index) {
        if (index < 0 || head == nullptr) {
            return false;
        }

        Node* cur = head;
        Node* prev = nullptr;

        for (int i = 0; i < index && cur != nullptr; i++) {
            prev = cur;
            cur = cur->next;
        }

        if (cur == nullptr) return false;

        if (prev == nullptr) {
            head = cur->next;
        } else {
            prev->next = cur->next;
        }

        if (cur == tail) {
            tail = prev;
        }

        delete cur;
        return true;
    }

    vector<int> getValues() {
        vector<int> values;
        Node* cur = head;

        while (cur != nullptr) {
            values.push_back(cur->val);
            cur = cur->next;
        }

        return values;
    }

    ~LinkedList() {
        Node* cur = head;

        while (cur != nullptr) {
            Node* nextNode = cur->next;
            delete cur;
            cur = nextNode;
        }
    }
};
