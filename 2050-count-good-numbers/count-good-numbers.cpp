class Solution {
public:
   
    int MOD=1e9+7;

    long long mypow(int x,long long n){
        if(n==0) return 1;
        long long half=mypow(x,n/2);
        if(n%2==0) return (half*half)%MOD;
        return (x*half*half)%MOD ;
    }
    
    int countGoodNumbers(long long n) {
        int start=0;

        long long ans=1;

        long long even= (n+1)/2;
        long long odd= (n/2);

        return ((mypow(5,even))%MOD * (mypow(4,odd))%MOD)%MOD;

        
    }
};