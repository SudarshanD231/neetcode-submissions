typedef struct list{
    int val;
    int minsofar;
    struct list* next;
}NODE;
typedef struct MinStack{
    NODE* head;

}MinStack;
MinStack* MinStackcreate(){
    MinStack* new_node=(MinStack*)malloc(sizeof(MinStack));
    new_node->head=NULL;
    return new_node;
}
void push(MinStack* n,int val){
    NODE* new_node=(NODE*)malloc(sizeof(NODE));
    new_node->val=val;
    new_node->next=n->head;
    if(!n->head || n->head->minsofar>val){
        new_node->minsofar=val;
    }else{
        new_node->minsofar=n->head->minsofar;
    }
    n->head=new_node;
}
void pop(MinStack* n){
    if(n->head->next){
        free(n->head);
        return ;
    }
    NODE* old=n->head;
    n->head=n->head->next;
    free(old);
    return;
}
int top(MinStack *n){
    return n->head->val;
}
int min(MinStack* n){
    return n->head->minsofar;
}

