//to avoid situations like (1,2,1) we sort the whole array first.

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>cur;
        backtrack(nums,0,cur,res);
        return res;
    }
private:
    void backtrack(vector<int>&nums,int start,vector<int>&cur,vector<vector<int>>&res){
        res.push_back(cur);
        for(int i=start;i<nums.size();i+=1){
            if(i>start && nums[i-1]==nums[i]){continue;}//skip duplicates at the same recursion level,we allow i==start bcs we need the first ones ,but then when we pop back and get the same element next ,we skip it ,basically skip duplicates at same recursion level.
            cur.push_back(nums[i]);
            backtrack(nums,i+1,cur,res);
            cur.pop_back();
        }
    }
};
