class Solution {
public: 
    vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j}); // push all the rotten into queue
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        int timer=0;
        while(!q.empty() && fresh>0){
            int size=q.size();

            while(size--){
                auto it =q.front();
                int x=it.first;
                int y=it.second;
                q.pop();

                for(int k=0;k<4;k++){
                    int new_x=x+dir[k][0];
                    int new_y=y+dir[k][1];

                    if(new_x>=0 && new_x<m && new_y>=0 && new_y<n && grid[new_x][new_y]==1){
                        q.push({new_x,new_y});
                        grid[new_x][new_y]=2; // make it rotten
                        fresh--;
                    }
                }
            }
            timer++;
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1; // if any fresh oranges are left
                }
            }
        }

        return timer;
    }
};