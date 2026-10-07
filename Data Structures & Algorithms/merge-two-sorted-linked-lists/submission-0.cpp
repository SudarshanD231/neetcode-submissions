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
 //if we dont use dummy nodes,when we do cur1->next=cur2 before cur1=cur->next,it breaks.
// we cant do NODE* dummy ,bcs doing tail->next will cause segmentation fault.
//do malloc dummy and thn free it in the end if u wanna do NODE* dummy.
typedef struct ListNode NODE;
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        NODE dummy;
        NODE* tail=&dummy;
        NODE* cur1=list1;
        NODE* cur2=list2;
        while(cur1 && cur2){
            if(cur1->val>=cur2->val){
                tail->next=cur2;
                cur2=cur2->next;
            }else{
                tail->next=cur1;
                cur1=cur1->next;
            }
            tail=tail->next;
        }
        if(!cur1){tail->next=cur2;}
        else{tail->next=cur1;}
        return dummy.next;
    }
};
