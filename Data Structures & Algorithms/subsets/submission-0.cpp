class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> res;
        backtrack(nums,0,cur,res);
        return res;
    }
private:
    void backtrack(vector<int>&nums,int start,vector<int>&cur,vector<vector<int>>&res){
        res.push_back(cur);
        for(int i=start;i<nums.size();i+=1){
            cur.push_back(nums[i]);//this line adds the cur number to the current subset
            backtrack(nums,i+1,cur,res);//this explores further and adds all of them to the cur subset
            cur.pop_back();//this pops back an element and the increment in the for loop switches branches 
        }
    }
};
