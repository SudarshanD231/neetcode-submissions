void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
//this is one pass approach .
void moveZeroes(int* nums,int numsSize){
    int l=0;
    for(int r=0;r<numsSize;r+=1){
        if(nums[r]){
            swap(&nums[r],&nums[l]);
            l+=1;
        }
    }
}
//this is two pass approach 
void moveZeroes(int* nums,int numsSize){
    int l=0;
    for(int r=0;r<numsSize;r+=1){
        if(nums[r]){
            nums[l++]=nums[r];
        }
    }
    while(l<numsSize){
        nums[l]=0;
        l+=1;
    }
}