//to use dp we must hv optimal substructure and recurring subprobelms,reccuring subproblems with recursion fuks up time complexity ,so we cache it with an array instead ,which will take o(n) time,another approach is top down ,where it takes constant space unlike memoization(caching).

class Solution {
public:
    int climbStairs(int n) {
        vector<int>memo(n+1,-1);
        return helper(n,memo);
            
        
    }
private:
    int helper(int n,vector<int>&memo){
        if(n==1 || n==2){return n;}
        if(memo[n]!=-1){return memo[n];}//this line checks whether the subproblem has already been solved,we do memo[n]!=-1 bcs we initialized the array with -1;
        memo[n]=helper(n-1,memo) +helper(n-2,memo);
        return memo[n];
    }
};
