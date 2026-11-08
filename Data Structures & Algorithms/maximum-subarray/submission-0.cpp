//can be solved using kadanes algo ,dk kadanes algo yet,can also be solved  using prefix sum,stroe prefix sum array ,max subarray tht ends at index j can be calcuated as prefix[j+1]-min_prefix;
//this algo can be space optimized to occupy const space
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size=nums.size();
        vector<int> prefix(size,0); 
        prefix[0]=nums[0];
        for(int i=1;i<size;i+=1){
            prefix[i]=nums[i]+prefix[i-1];
        }
        int max_sum=prefix[0];
        int min_prefix=0;
        for(int j=0;j<nums.size();j+=1){
            max_sum=max(max_sum,prefix[j]-min_prefix);
            min_prefix=min(min_prefix,prefix[j]);
        }
        return max_sum;
    }
};
