class Solution {
public:
    vector<vector<int>>c = {
        {1,1},{-1,-1},{1,0},{0,1},{-1,0},{0,-1},{-1,1},{1,-1}
    };

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // BFS returns the shortest Path ---don't worry and excite !
       int n = grid.size();
        int x_src = 0,y_src = 0;
        int x_tar = n-1,y_tar = n-1;
        if(grid[x_src][y_src] != 0 || grid[x_tar][y_tar] != 0) return -1;
        queue<pair<pair<int,int>,int>>q; // stores {x_new,y_new}{steps}
        vector<vector<int>>vis(n,vector<int>(n,0));
        q.push({{0,0},1}); // we have to count the src also
        vis[0][0] = 1;
        while(!q.empty()){
                int x = q.front().first.first;
                int y = q.front().first.second;
                int curr_steps=q.front().second;
                q.pop();
                if(x == n-1 && y == n-1 && grid[x][y] == 0) return curr_steps;
                for(int k=0;k<c.size();k++){
                    int x_new = x + c[k][0];
                    int y_new = y + c[k][1];
                    if(x_new >=0 && y_new >=0 && x_new < n
                    && y_new < n && grid[x_new][y_new] == 0 && !vis[x_new][y_new])
                    {
                        vis[x_new][y_new] = 1; 
                        q.push({{x_new,y_new},curr_steps+1});
                    }
                }
        }
            
        return -1;
    }
};