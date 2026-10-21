class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        deque<int> q;

        int n=nums.size();
        for(auto it: nums){
            q.push_back(it);
        }

        while(k--){
            int ele=q.back();
            q.pop_back();
            q.push_front(ele);
        }

        for(int i=0;i<n;i++){
            nums[i]=q.front();
            q.pop_front();
        }

    }
};