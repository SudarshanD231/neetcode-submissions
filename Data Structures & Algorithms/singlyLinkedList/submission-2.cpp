#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
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

    vector<int> getValues() {
        vector<int> arr;
        Node* cur = head;

        while (cur != nullptr) {
            arr.push_back(cur->val);
            cur = cur->next;
        }

        return arr;
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

        if (cur == nullptr) {
            return false;
        }

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

    ~LinkedList() {
        Node* cur = head;

        while (cur != nullptr) {
            Node* nextNode = cur->next;
            delete cur;
            cur = nextNode;
        }
    }
};