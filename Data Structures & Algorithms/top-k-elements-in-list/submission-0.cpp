typedef struct hahsmap{
    int val;
    int count;
    struct hashmap* next;
}ENTRY;
typedef struct node{
    int val;
    struct node* next;
}NODE;
int* topKfrequent(int* nums,int n,int k,int* returnSize){
    int cap=2*n +1;
    ENTRY** table=(ENTRY**)calloc(cap,sizeof(ENTRY*));
    for(int i=0;i<n;i+=1){
        int h=(unsigned)nums[i]%cap;
        ENTRY* p=table[h];
        while(p && p->val!=nums[i]){
            p=p->next;
       }
       if(p && p->val=nums[i]){
        p->count+=1;
       }else{
        ENTRY* e=(ENTRY*)malloc(sizeof(ENTRY));
        e->val=nums[i];
        e->count+=1;
        e->next=table[h];
        table[h]=e;
       }
    }
    NODE** buckets=(NODE**)calloc(cap,sizeof(NODE*));
    for(int i=0;i<cap;i+=1){
        for(ENTRY* p=table[i];p!=NULL;p=p->next){
            NODE* new_node=malloc(sizeof(NODE));
            new_node->val=p->val;
            new_node->next=bucket[p->count];
            bucket[p->count]=new_node;
        }
    }
    int* res=calloc(k*sizeof(int));
    *returnSize=0;
    for(int f=n;f>0 && *returnSize<k ;f-=1){
        for(NODE* n=bucket[f];n && *returnSize<k;n=n->next){
            res[*(returnSize)++]=n->val;
        }
    }
    
}