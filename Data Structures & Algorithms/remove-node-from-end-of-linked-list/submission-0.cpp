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
typedef struct ListNode NODE;
int count(NODE* head){
    int sz=0;
    if(!head){return sz;}
    
    NODE* cur=head;
    while(cur){
        sz+=1;
        cur=cur->next;
    }
    return sz;
} 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz=count(head);
    if(sz==n){
        NODE* del=head;
        head= head->next;
        delete(del);
        return head;
    }
    
    NODE* prev=NULL;
    NODE* cur=head;
    for(int i=0;i<sz-n;i+=1){
        prev=cur;
        cur=cur->next;
    }
    prev->next=cur->next;
    delete (cur);
    return head;
    }
};
