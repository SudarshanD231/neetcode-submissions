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
//a divide and conquer soln is better bcs it merges two lists at once,basically pairs it up,merging each list takes O(n.k) time whereas divide and conquer takes O(nlogk) time
typedef struct ListNode NODE;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){return NULL;}
        while(lists.size()>1){
            vector<NODE*> merged_list;
            for(int i=0;i<lists.size();i+=2){
                NODE* l1=lists[i];
                NODE* l2 = (i+1)<lists.size() ? lists[i+1]:nullptr;
                merged_list.push_back(merge(l1,l2));
            }
            lists=merged_list;


        }
        return lists[0];


    }
    private:
    NODE* merge(NODE* l1,NODE* l2){
        if(!l1){return l2;}
        if(!l2){return l1;}
        NODE dummy;
        dummy.next=NULL;
        NODE* cur=&dummy;
        while(l1 && l2){
            if(l1->val<=l2->val){
                cur->next=l1;
                l1=l1->next;
            }else{
                cur->next=l2;
                l2=l2->next;
            } 
            cur=cur->next;
        }
        if(!l1){
            cur->next=l2;
        }else{
            cur->next=l1;
        }
        return dummy.next;
    }
};
