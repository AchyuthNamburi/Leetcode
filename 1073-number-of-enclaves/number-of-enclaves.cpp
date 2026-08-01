class Solution {
public:
    typedef pair<int,int> P;
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<P> q;
        // STEP 1:
        // Push all boundary land cells (1's) into the queue.
        // These cells can already reach the boundary,
        // so they are NOT enclaves.
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 1 && (i == 0 || i == m-1 || j == 0 || j == n-1)) {
                    grid[i][j] = '#';
                    q.push({i,j});
                }
            }
        }

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        // STEP 2:
        // Perform BFS from all boundary land cells.
        // Every land cell connected to the boundary
        // is also NOT an enclave.  

        while(!q.empty()) {
            auto [r,c] = q.front();
            q.pop();
            
            for(int k=0;k<4;k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] == 1){
                   // Mark this land cell as visited because
                    // it is connected to the boundary.

                    grid[nr][nc] = '#'; // This land cell can reach the boundary,
                        // so it cannot be an enclave.
                    q.push({nr,nc});
                }
            }
        }

        // STEP 3:
        // count the no of land cells which we  cannot walk 
        int count=0;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 1) {
                   count++;
                }
            }
        }

        return count;
    }
};