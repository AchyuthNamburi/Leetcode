class Solution {
public:
vector<vector<int>> coordinates = {{-1,0},{1,0},{0,1},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // bfs on grid
        queue<pair<int,int>>q;
        int fresh = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }
        int steps = 0;
        while(!q.empty() && fresh > 0){
            int size = q.size();
            while(size--){ // multi source BFS
                auto [x,y] = q.front();
                q.pop();
                for(int k = 0;k<coordinates.size();k++){
                    int x_new = x + coordinates[k][0];
                    int y_new = y + coordinates[k][1];
                    if(x_new >=0 && y_new >=0 && x_new < m && y_new < n && grid[x_new][y_new] == 1){
                    grid[x_new][y_new] = 2; // rot it
                    q.push({x_new,y_new});
                    fresh--;
                    }
                }
            }
            steps++;
        }
        if(fresh == 0) return steps;
        else return -1;
    }
};