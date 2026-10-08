/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* rev(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* next;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    ListNode* merge_alt(ListNode* head1, ListNode* head2) {
        ListNode dummy;
        ListNode* tail = &dummy;
        ListNode* cur1 = head1;
        ListNode* cur2 = head2;
        while (cur1 && cur2) {
            tail->next = cur1;
            tail = tail->next;
            cur1 = cur1->next;
            tail->next = cur2;
            tail = tail->next;
            cur2 = cur2->next;
        }
        if (!cur2) {
            tail->next = cur1;
        } else {
            tail->next = cur2;
        }
        return dummy.next;
    }

public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;
        while (slow && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* part2 = slow->next;
        slow->next = nullptr;
        part2 = rev(part2);
        
        // head is updated in place via merge_alt execution
        head = merge_alt(head, part2);
    }
};
