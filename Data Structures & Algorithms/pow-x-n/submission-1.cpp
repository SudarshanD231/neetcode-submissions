class Solution {
public:
    double myPow(double x, int n) {
        double a=1;
        long  exp=n;
        if(exp<0){
            x=1/x;
            exp=-exp;
        }if(exp==0){return 1;}
        while(exp>0){
            if(exp%2==1){
                a*=x;
            }
            x*=x;
            exp/=2;
        }
        return a;
    }
};
