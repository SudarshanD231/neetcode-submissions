typedef struct node{
    int data;
    struct node* next;
}NODE;
bool check_cycle(NODE* head){
    NODE* slow=head;
    NODE* fast=head;
    
    while(fast && fast->next){//dont need to check for slow bcs slow cant advance faster than fast.
        slow=slow->next;
        fast=fast->next->next
        if(slow==fast){//condition shld be after advancing otherwise it will return true immediately since both r head.
            return true;
        }
        
    }
    return false;
}