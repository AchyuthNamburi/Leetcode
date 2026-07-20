class Solution {
public:
    double solve(double x,int n){
        if(n==0) return 1.0;
        long long N=n;
        if(n<0){
            x=1/x;
            N=-N;
        }
        double half=solve(x,N/2);
        if(N%2==0) return half*half;
        return x*half*half;
    }
    double myPow(double x, int n) {
        return solve(x,n);
    }
};