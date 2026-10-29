class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>> pq;

        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        long long score=0;

        while(k--){
            int a=pq.top().first;
            int idx=pq.top().second;
            pq.pop();
           
            score+=a;
            nums[idx]=ceil(nums[idx]/3.0);
            
            pq.push({nums[idx],idx});
           
        }

        return score;
    }
};