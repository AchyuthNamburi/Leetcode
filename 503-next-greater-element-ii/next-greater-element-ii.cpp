class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
           
           int n=nums.size();

        vector<int> ans(n,-1);
        stack<int> st; // store indexes ( not the elem)

        // int start_idx=0;

        for(int i=0;i<2*n;i++){ // traverse 2*n the length
            int idx=i%n;
            while(!st.empty() && nums[idx]>nums[st.top()]){
                ans[st.top()]=nums[idx];
                st.pop();
            }
            st.push(idx);
        }

        return ans;

        
        
    }
};