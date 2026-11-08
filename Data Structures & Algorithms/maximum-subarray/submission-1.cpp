//space optimized soln.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prefix=0;
        int min_prefix=0;
        int max_sum=INT_MIN;
        for(int num: nums){
            prefix+=num;
            max_sum=max(max_sum,prefix-min_prefix);
            min_prefix=min(prefix,min_prefix);
        }
        return max_sum;
    }
};
