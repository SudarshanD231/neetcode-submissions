class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int l=0;
       for(int r=0;r<=nums.size()-1;r+=1){
            if(nums[r]){
                nums[l++]=nums[r];
            }
       }
       while(l<nums.size()){
            nums[l]=0;
            l+=1;
       } 
    }
};