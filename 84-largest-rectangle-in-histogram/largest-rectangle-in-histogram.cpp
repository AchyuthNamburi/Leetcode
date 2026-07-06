class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n=nums.size();
        
        stack<int> st1; //to store indices

        vector<int> PSE(n, -1);
        for(int i=0;i<n;i++){
            while(!st1.empty() && nums[st1.top()]>nums[i]){
                st1.pop();
            }
            if(!st1.empty()){
                PSE[i]=st1.top();
            }

            st1.push(i);
        }

        stack<int> st2; // store indices
        vector<int> NSE(n,n);
        for(int i = n-1; i >= 0; i--){
            while(!st2.empty() && nums[st2.top()]>=nums[i]){ // if violates then only pop
                st2.pop();
            }

            if(!st2.empty()){
                NSE[i] = st2.top();
            }

            st2.push(i);
        }

        int maxArea=0;

        for(int i=0;i<nums.size();i++){
            int width=(NSE[i] - 1) - (PSE[i] + 1) + 1;
            maxArea=max(maxArea,nums[i]*width);
        }

        return maxArea;




    }
};