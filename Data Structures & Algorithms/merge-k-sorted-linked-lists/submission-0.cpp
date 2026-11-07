//my approach was merging the list one by one 
typedef struct node{
    int val;
    struct node* next;
}NODE;
NODE* merge(NODE* l1,NODE* l2){
    if(!l1){return l2;}
    if(!l2){return l1;}
    NODE dummy;
    
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
NODE* mergeKlists(NODE** arr,int k){

    for(int i=1;i<k;i+=1){
        arr[i]=merge(arr[i],arr[i-1]);
    }
    return arr[k-1];


}