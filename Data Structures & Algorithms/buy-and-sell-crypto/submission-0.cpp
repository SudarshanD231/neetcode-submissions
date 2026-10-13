int maxProfit(int* nums,int n){
    int l=0;
    int r=1;
    int maxp=0;
    while(r<n){
        if(nums[l]<nums[r]){
            l=r;
        }else{
            int profit=nums[r]-nums[l];
            if(profit>maxp){maxp=profit;}
        }
        r+=1;
    }
    return maxp;

}