class Solution {
public:
    vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1}};

    void runBFS(vector<vector<char>>& grid,int i,int j,vector<vector<int>>& visited){
        int m=grid.size();
        int n=grid[0].size();

        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]=1; // make it visited

        while(!q.empty()){
            int curr_i=q.front().first;
            int curr_j=q.front().second;
            q.pop();

            for(auto it:dir){
                int new_i=curr_i+it[0];
                int new_j=curr_j+it[1];

                if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && grid[new_i][new_j]=='1' && visited[new_i][new_j]==0){
                    visited[new_i][new_j]=1;
                    q.push({new_i,new_j});
                }
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        //BFS 
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));

        int i,j,islands=0;

        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(grid[i][j]=='1' && visited[i][j]!=1){
                    islands++;
                    runBFS(grid,i,j,visited);
                }
            }
        }

        return islands;
    }
};