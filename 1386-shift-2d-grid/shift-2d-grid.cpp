class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ans=grid;
        int m=grid.size();
        int n=grid[0].size();

        deque<int> temp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                temp.push_back(grid[i][j]);
            }
        }

        while(k){
            temp.push_front(temp[temp.size()-1]);
            temp.pop_back();
            k--;
        }
        int p=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=temp[p++];
            }
        }

        return ans;
        
    }
};