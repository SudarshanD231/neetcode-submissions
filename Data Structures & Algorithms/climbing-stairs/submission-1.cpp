//space optimized soln

class Solution {
public:
    int climbStairs(int n) {
        if(n==1 || n==2){return n;}
        int prev2=1;//ways to reach step1;
        int prev1=2;//ways to reach step 2;
        for (int i=3;i<=n;i+=1){
            int cur=prev2+prev1;
            prev2=prev1;
            prev1=cur;
        }
        return prev1;
    }
};
