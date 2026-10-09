class Solution {
public:
    double myPow(double x, int n) {
        double a=1;
        if(n<0){
            x=1/x;
            n=-n;
        }
        if(n==0){return 1;}
        for(int i=0;i<n;i+=1){
            a*=x;
        }
        return a;
    }
};
