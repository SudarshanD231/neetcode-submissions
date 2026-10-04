//two-poiner 
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int numsSize=numbers.size();
        int i=0;
        int j=numsSize-1;
        while(i<j){
            if(numbers[i]+numbers[j]==target){return {i+1,j+1};};
            if(numbers[i]+numbers[j]>target){j-=1;};
            if(numbers[i]+numbers[j]<target){i+=1;};
        }
        return {-1,-1};
    }
};
