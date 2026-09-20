class Solution {
public:
    bool isPerfectSquare(int num) {
        //basecase --if the unit digit is not in {0,1,4,9,6,5} then not a perfect square

        if(num%10==2 || num%10==3 || num%10==7 || num%10==8 ) return false;

        if(num==1) return true;

        long long low=1;
        long long high=num;

        while(low<=high){
            long long mid=low+(high-low)/2;
            if(mid*mid==num) return true;
            else if(mid*mid > num) high=mid-1;
            else low=mid+1;
        }

        return false;
    }
};