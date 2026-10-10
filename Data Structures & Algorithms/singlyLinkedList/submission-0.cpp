// my C soln.
typedef struct node{
    int val;
    struct node* next;
}NODE;
typedef struct list{
    NODE* head;
    NODE* tail;
}LIST;
LIST* create(){
    LIST* l=(LIST*)malloc(sizeof(LIST));
    l->head=l->tail=NULL;
    return l;
}
void insertHead(int val,LIST* l){
    NODE* new_node=(NODE*)malloc(sizeof(NODE));
    new_node->val=val;
    new_node->next=l->head;
    if(!l->head){
        l->tail=new_node;
    }
    l->head=new_node;
}
void insertTail(int val,LIST* l){
    NODE* new_node=(NODE*)malloc(sizeof(NODE));
    new_node->val=val;
    new_node->next=NULL;
    if(!l->head){
        l->head=l->tail=new_node;
    }else{
        l->tail->next=new_node;
        l->tail=new_node;
    }
}
int* getvalues(LIST* l){
    NODE* cur=l->head;
    int count=0;
    while(cur){
        count+=1;
        cur=cur->next;
    }
    int* arr=(int*)malloc(count*sizeof(int));
    cur=l->head;
    for(int i=0;i<count;i+=1){
        arr[i]=cur->val;
        cur=cur->next;
    }
    return arr;
}
bool remove(int i,LIST* l){
    if(!l->head || i<0){return false;}
    NODE* cur=l->head;
    NODE* prev=NULL;
    for(int a=0;a<i;a+=1){
        prev=cur;
        cur=cur->next;
    }
    if(!cur){return false;}
    if(!prev){
        l->head=l->head->next;
    }else{
        prev->next=cur->next;
    }
    if(cur==l->tail){
        l->tail=prev;

    }
    free(cur);
    return true;

}
