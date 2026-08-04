class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorr=start ^ goal;

        return __popcount(xorr);
    }
};