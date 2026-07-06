class Solution {
public:
    
    // solve is the largest rectangle code 
    int solve(vector<int>& heights){
        int n=heights.size();
         stack<int> st1; //to store indices

        vector<int> PSE(n, -1);
        for(int i=0;i<n;i++){
            while(!st1.empty() && heights[st1.top()]>heights[i]){
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
            while(!st2.empty() && heights[st2.top()]>=heights[i]){ // if violates then only pop
                st2.pop();
            }

            if(!st2.empty()){
                NSE[i] = st2.top();
            }

            st2.push(i);
        }

        int maxArea=0;

        for(int i=0;i<heights.size();i++){
            int width=(NSE[i] - 1) - (PSE[i] + 1) + 1; 
            maxArea=max(maxArea,heights[i]*width);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
         // trick convert this entire matrix into a histogram and find the largest rectangle from the Histogram

         int m=matrix.size();
         int n=matrix[0].size();

         vector<int> heights(n,0);
         int ans=0;

         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    heights[j]+=1;
                }
                else{
                    heights[j]=0;
                }
            }

             ans = max(ans, solve(heights)); // for each row find the histogram and then find the largest rectangle in that 
         }

         return ans;



        

    }
};