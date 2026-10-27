int search (int* nums,int numsSize,int target){
    int l=0;
    int r=numsSize-1;
    while(l<r){
        int mid=l+ (r-l)/2;
        if(nums[mid]>nums[right])//pivot is to right of mid
        {
            l=mid+1;// we do l=mid +1 and not l= mid bcs if the condition is satisified we know for sure tht mid element is not pivot
        }else{
            r=mid;//not r=mid-1 bcs mid element might be pivot
        }
    }
    int pivot=l;
    l=0;
    r=numsSize-1;
    if(target>=nums[pivot] && target<=nums[r]){
        l=pivot;
    }else{
        r=pivot-1
    }
    while(l<=r){
        int mid=l +(r-l)/2;
        if(nums[mid]==target){return mid}
        else if(nums[mid]>target){r=mid-1;}
        else{l=m+1;}
    }
    return -1;

}