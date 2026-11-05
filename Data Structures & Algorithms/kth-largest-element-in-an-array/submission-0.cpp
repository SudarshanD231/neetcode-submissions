typedef struct heap{
    int k;
    int size;
    int* heap;

}Heap;
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubbleup(int* heap,int index){
    int parent=(index-1)/2;
    while(parent>=0){
        if(heap[parent]>heap[index]){
            swap(&heap[parent],&heap[index]);
            index=parent;
            parent=(index-1)/2;
        }else{
            break;
        }
    }
}
void heapifydown(int* heap,int size,int index){
    while(1){
        int left=2*index +1;
        int right=2*index +2;
        int smallest=index;
        if(left<size && heap[smallest]>heap[left]){
            smallest=left;
        }
        if(right<size && heap[smallest]>heap[right]){
            smallest=right;
        }
        if(smallest==index){break;}
        swap(&heap[smallest],&heap[index]);
        index=smallest;
    }
}
int findKthlargest(int* nums,int k,int numsSize){
    Heap* obj=(Heap*)malloc(sizeof(Heap));
    obj->heap=malloc(k*sizeof(int));
    obj->k=k;
    obj->size=0;
    for(int i=0;i<numsSize;i+=1){
        if(obj->size<obj->k){
            obj->heap[obj->size++]=nums[i];
            bubbleup(obj->heap,obj->size-1);
        }else if(nums[i]>obj->heap[0]){
            obj->heap[0]=nums[i];
            heapifydown(obj->heap,obj->size,0);
        }
    }
    return obj->heap[0];
}