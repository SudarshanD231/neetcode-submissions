#define CAPACITY 10007
typedef struct node{
    int val;
    struct node* next;
    struct node* random;
}NODE;
typedef struct hashmap{
    NODE* key;
    NODE* val;
    struct hashmap* next;
}HASHMAP;
size_t hash_func(NODE* key){
    return (uintptr_t)key % CAPACITY;
}

void insert(NODE* key,HASHMAP** hashmap){
    size_t idx=hash_func(key);
    NODE* new_node=(NODE*)calloc(1,sizeof(NODE));
    new_node->val=key->val;
    HASHMAP* entry=malloc(sizeof(HASHMAP));
    entry->key=key;
    entry->val=new_node;
    entry->next=hashmap[idx];
    hashmap[idx]=entry;
}
NODE* get(NODE* key,HASHMAP** hashmap){
    size_t idx=hash_func(key);
    HASHMAP* entry=hashmap[idx];
    while(entry){
        if(entry->key==key){
            return entry->val;
        }
        entry=entry->next;
    }
    return NULL;
}
NODE* copyRandomList(NODE* head){
    if(!head){return NULL;}
    NODE* cur=head;
    HASHMAP** hashmap=(HASHMAP**)calloc(CAPACITY,sizeof(HASHMAP*));
    while(cur){
        insert(cur,hashmap);
        cur=cur->next;
    }
    cur=head;
    while(cur){
        NODE* copy=get(cur,hashmap);
        copy->next=get(cur->next,hashmap);
        copy->random=get(cur->random,hashmap);
        cur=cur->next;
    }
    return get(head,hashmap);
}