class Solution {
public:
    int rob(vector<int>& nums) {
        int max;
        int cur1=0;
        int cur2=0;
        for(int i=0;i<nums.size();i+=2){
            cur1+=nums[i];
        }
        for(int i=1;i<nums.size();i+=2){
            cur2+=nums[i];
        }
        if(cur1>=cur2){max=cur1;}
        else{max=cur2;}
        return max;
    }
};
