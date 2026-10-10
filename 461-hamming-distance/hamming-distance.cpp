class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt=0;

        int xorr=x^y;

        while(xorr){
            xorr=xorr & (xorr-1);
            cnt++;
        }

        return cnt;
    }
};