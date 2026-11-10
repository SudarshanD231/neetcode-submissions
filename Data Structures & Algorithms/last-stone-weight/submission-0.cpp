void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapifyup(int* heap,int idx){
    
    while(idx>0){
        int parent=(idx-1)/2;
        if(heap[parent]<heap[idx]){
            swap(&heap[parent],&heap[idx]);
            idx=parent;
        }else{
            break;
        }
    } 
    
}
int* heapify(int* nums,int numsSize){
    for(int i=1;i<numsSize;i+=1){
        heapifyup(nums,i);
    }
    return nums;

}
void bubbledown(int* heap,int idx,int size){
    while(1){
        int largest=idx;
        int left=2*idx +1;
        int right=2*idx+2;
        if(left<size && heap[largest]<heap[left] ){
            largest=left;
        }if(right<size && heap[largest]<heap[right]){
            largest=right;
        }
        if(largest!=idx){swap(&heap[largest],&heap[idx]);
        idx=largest;}else{break;}
    }
        
}

int lastStoneWeight(int* stones, int stonesSize) {
    stones=heapify(stones,stonesSize);
    int curSize=stonesSize;
    while(curSize>1){
        int x=stones[0];
        stones[0]=stones[curSize-1];
        curSize-=1;
        bubbledown(stones,0,curSize);
        if(curSize==0){return x;}
        int y=stones[0];
        stones[0]=stones[curSize-1];
        curSize-=1;
        bubbledown(stones,0,curSize);
        if(y!=x){
            stones[curSize]=x-y;
            curSize+=1;
            heapifyup(stones,curSize-1);
        }
    }
    return curSize==0 ? 0:stones[0];
}
