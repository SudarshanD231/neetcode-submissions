int* plusOne(int* nums,int numsSize){
    if(nums[numsSize-1]!=9){
        nums[numsSize-1]+=1;
        return nums;
    }else{
        int i=numsSize-1;
        while(i>=0 && nums[i]==9){
            nums[i]=0;
            i-=1;
        }
        if(i>=0){
            nums[i]+=1;
            return nums;
        }
        int* new_arr=(int*)calloc(numsSize+1,sizeof(int));
        new_arr[0]=1;
        return new_arr;
    }
}