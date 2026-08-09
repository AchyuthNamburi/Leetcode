class Solution {
public:
    long long solve(int mid,vector<int>& piles){
        long long cnt=0;
        for(auto it : piles){
            cnt+=(it + mid -1)/mid;
        }

        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());

        int ans=high; // actually we want min value ...so we declare with max val

        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(mid,piles)<=h){ // curr mid works but still search for the less val
                ans=mid;
                high=mid-1;
            }
            else if(solve(mid,piles)>h){
                low=mid+1;
            }  
        }

        return ans;
    }
};