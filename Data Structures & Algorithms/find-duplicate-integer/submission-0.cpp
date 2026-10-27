//i had a question abt if the array had 1,2,2,4,5,6,7 as elements ,but all elements shld be inside range [1,6] inclusive,so 7 cant be there//
int binarysearchduplicate(int* nums,numsSize){
    int l=1;
    int r=numsSize-1;
    
    while(l<r){
        int count=0;
        int mid=l+ (r-l)/2;
        for(int i=0;i<=numsSize-1;i+=1){
            
            if(nums[i]<=mid){count+=1;}
        }
        if(count>mid){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    return l;
}