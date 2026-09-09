class Solution {
public:
    typedef long long ll;
    long long countCommas(long long n) {
        if(n<1000) return 0;
        
        ll cnt=0;
        for(ll i=1000;i<=n;i*=1000){
            cnt+=(n-i+1);
        }
        
        return cnt;

    }
};