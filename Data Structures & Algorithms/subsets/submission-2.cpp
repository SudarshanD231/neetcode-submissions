//iteration soln,this uses more space s compared to backtracking

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        res.push_back({});
        for (int num:nums){
            int size=res.size();
            for(int i=0;i<size;i+=1){
                vector<int>new_subarray=res[i];
                new_subarray.push_back(num);
                res.push_back(new_subarray);
            }
        }
        return res;
    }
};
