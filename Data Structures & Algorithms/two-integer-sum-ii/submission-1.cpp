//brute force soln,learnt arrays are initialized with {} and not [];
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size=numbers.size();
        for(int i=0;i<size-1;i+=1){
            int present=target-numbers[i];
            for(int j=i+1;j<size;j+=1){
                if(numbers[j]==present){
                    vector<int> result={i+1,j+1};
                    return result;
                }
            }
        }
    return {0,0};  
    
};
};
