class Solution {
public:
    int arrangeCoins(int n) {
        long long sum=0;
        int i=1;
        int cnt=0;

        while(sum<=n){
            sum+=i;
            cnt++;
            i++;
        }

        return cnt-1;


    }
};