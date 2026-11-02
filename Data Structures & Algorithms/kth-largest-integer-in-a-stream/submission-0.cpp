
typedef struct {
    int k;
    int* heap;
    int size;
} KthLargest;
int kthLargestAdd(KthLargest* obj, int val);   // ← function prototype

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj=malloc(sizeof(KthLargest));
    obj->k=k;
    obj->size=0;
    obj->heap=malloc(k*sizeof(int));
    for(int i=0;i<numsSize;i+=1){
        kthLargestAdd(obj,nums[i]);
    }
    return obj;
}
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubbleup(int* heap,int index){
    
    while(index>0){
        int parent=(index-1)/2;
        if(heap[parent]<=heap[index]){
            break;
        }
        swap(&heap[index],&heap[parent]);
        index=parent;
    }
}
void heapifyDown(int* heap,int size,int index){
    while(1){
        int smallest=index;
        int left=2*index +1;
        int right=2*index+2;
        if(left<size && heap[smallest]>heap[left] ){
            smallest=left;
        }if(right<size && heap[smallest]>heap[right]){
            smallest=right;
        }
        if(smallest!=index){swap(&heap[smallest],&heap[index]);
        index=smallest;}else{break;}
    }
};
void heapPush(KthLargest* obj,int val){
    obj->heap[obj->size]=val;
    bubbleup(obj->heap,obj->size);
    obj->size+=1;

}
void heapPop(KthLargest* obj){
    if(obj->size==0){
        return ;
    }
    int pop=obj->heap[0];
    obj->heap[0]=obj->heap[obj->size-1];
    obj->size-=1;
    heapifyDown(obj->heap,obj->size,0);
}

int kthLargestAdd(KthLargest* obj, int val) {
    if(obj->size<obj->k){
        heapPush(obj,val);

    }else if(val>obj->heap[0]){
        obj->heap[0]=val;
        heapifyDown(obj->heap,obj->size,0);
    }
    return obj->heap[0];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}
