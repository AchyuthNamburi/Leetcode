class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt=0;

        if(n<0) return false;

        while(n){
            n=n&(n-1);
            cnt++;
        }

        return cnt==1;
    }
};