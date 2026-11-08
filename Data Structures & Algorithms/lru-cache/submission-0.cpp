#define MAX1 5000
typedef struct node{
    int key;
    int val;
    struct node* next;
    struct node* prev;

}NODE;
typedef struct hashmap{
    NODE* node;
    struct hashmap* next;
}hashmap;
hashmap** map=NULL;
typedef struct {
    NODE* start;
    NODE* end;
    int cap;
    int size;
} LRUCache;


LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* obj=(LRUCache*)malloc(sizeof(LRUCache));
    obj->cap=capacity;
    obj->start=obj->end=NULL;
    map=calloc(MAX1,sizeof(hashmap*));
    obj->size=0;
    return obj;
}
NODE* remove_(LRUCache* obj,NODE* x){
    if(!x){return NULL;}
    if(x->prev){
        x->prev->next=x->next;

    }else{
        obj->start=x->next;
    }
    if(x->next){
        x->next->prev=x->prev;
    }else{
        obj->end=x->prev;
    }
    x->prev=x->next=NULL;
    return x;
}
void insert(LRUCache* obj,NODE* x){
    x->prev=obj->end;
    x->next=NULL;
    if(obj->end){obj->end->next=x;}
    else{obj->start=x;}
    
    obj->end=x;
}

int lRUCacheGet(LRUCache* obj, int key) {
    if(!map[key%MAX1]){return -1;}
    hashmap* cur=map[key%MAX1];
    while(cur && cur->node->key!=key){
        cur=cur->next;
    }
    if( cur && cur->node->key==key){
        insert(obj,remove_(obj,cur->node));
        return cur->node->val;
    }
    return -1;
}

void lRUCachePut(LRUCache* obj, int key, int val) {

    hashmap* cur=map[key%MAX1];
    while(cur && cur->node->key!=key){
        cur=cur->next;
    }
    if(cur){
        cur->node->val=val;
        insert(obj, remove_(obj, cur->node));
        return ;
    }
    if(obj->size>=obj->cap){
        NODE* temp=obj->start;
        remove_(obj,temp);
        hashmap* entry=map[temp->key % MAX1];
        hashmap* prev=NULL;
        while(entry && entry->node!=temp){
            prev=entry;
            entry=entry->next;
        }
        if(entry){
            if(prev){prev->next=entry->next;}
            else{map[temp->key %MAX1] =entry->next;}
            free(entry);
        }
        obj->size-=1;
        free(temp);
    }
    NODE* new_node = malloc(sizeof(NODE));
    new_node->prev = new_node->next = NULL;
    new_node->key = key;
    new_node->val = val;
    insert(obj, new_node);
    obj->size += 1;

    hashmap* entry = malloc(sizeof(hashmap));
    entry->node = new_node;
    entry->next = map[key % MAX1];
    map[key % MAX1] = entry;


}

void lRUCacheFree(LRUCache* obj) {
    for(int i=0;i<MAX1;i+=1){
        hashmap* cur=map[i];
        while(cur){
            hashmap* temp=cur;
            cur=cur->next;
            free(temp);
        }
    }
    free(map);
    NODE* cur=obj->start;
    while(cur){
        NODE* temp=cur;
        cur=cur->next;
        free(temp);
    }
    free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/