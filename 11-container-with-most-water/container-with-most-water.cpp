class Solution {
public:
    int maxArea(vector<int>& heights) {
        // we will do with 2 ptrs 
        int left=0;
        int right=heights.size()-1;
        int max_area=0;

        while(left<right){
            int len=(right-left);
            int breadth=min(heights[left],heights[right]);
            max_area=max(max_area,len*breadth);

            if(heights[left]<heights[right]) left++;
            else right--;

        }

        return max_area;
    }
};