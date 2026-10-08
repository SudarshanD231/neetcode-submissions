typedef struct list{
    int data;
    struct list* next;
}NODE;
NODE* rev(NODE* head){
    NODE* prev=NULL;
    NODE* cur=head;
    NODE* next;
    while(cur){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    return prev;
}
NODE* merge_alt(NODE* head1,NODE* head2){
    NODE dummy;
    NODE* tail= &dummy;
    NODE* cur1=head1;
    NODE* cur2=head2;
    while(cur1 && cur2){
        tail->next=cur1;
        tail=tail->next;
        cur1=cur1->next;
        tail->next=cur2;
        tail=tail->next;
        cur2=cur2->next;
    }
    if(!cur2){
        tail->next=cur1;
    }else{
        tail->next=cur2;
    }
    return dummy.next;
}
NODE* reorder(NODE* head){
    NODE* slow=head;
    NODE* fast=head;
    while(slow && fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    NODE* part2=slow->next;
    slow->next=NULL;
    part2=rev(part2);
    return merge_alt(head,part2);

}