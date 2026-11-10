class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        vector<int>cur;
        sort(nums.begin(),nums.end());
        bcktrck(nums,0,target,cur,res);
        return res;
    }
private:
    void bcktrck(vector<int>&nums,int start,int rem,vector<int>&cur,vector<vector<int>>&res){
        if(rem==0){
            res.push_back(cur);
            break;
        }
        for(int i=start;i<nums.size();i+=1){
            if(nums[i]>rem){break;}
            cur.push_back(nums[i]);
            bcktrck(nums,i,rem-nums[i],cur,res);//here we pass i as argument instead of i+1 bcs same elements r allowed,if not allowed ,we wld do i+1.
            cur.pop_back();
        }
    }
};
