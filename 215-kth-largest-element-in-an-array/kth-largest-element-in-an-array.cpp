class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,
                    vector<int>>pq; //becareful this is max_heap by default 
                                    // if u write greater<int> then it is minHeap
    

        for(auto it:nums){
            pq.push(it);
        }

        while(k-1){
            pq.pop();
            k--;
        }

        return pq.top();
    }
};