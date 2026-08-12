class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n=nums.size();
        priority_queue<double> pq;
        for(auto it : nums){
            pq.push(it);
        }

        double sum=accumulate(nums.begin(),nums.end(),0.0);

        double half=sum/2;
        int k=0;

        while(sum>half && !pq.empty()){
            if(sum==half) return k;
            double top=pq.top();
            pq.pop();
            top/=2;
            k++;
            sum-=top;
            if(sum==half) return k;
            pq.push(top);
            
        }

        return k;
    }
};