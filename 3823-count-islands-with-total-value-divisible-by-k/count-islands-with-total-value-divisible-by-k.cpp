class Solution {
public:
    vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));

        long long sum=0;
        int cnt=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0 && !visited[i][j]){
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j]=1;
                    sum=0;
                    while(!q.empty()){
                        auto [x,y]=q.front();
                        q.pop();
                        sum+=grid[x][y];

                        for(int i=0;i<4;i++){
                            int nx=x+dir[i][0];
                            int ny=y+dir[i][1];

                            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]>0 && !visited[nx][ny]){
                                
                                q.push({nx,ny});
                                visited[nx][ny]=1;
                            }
                        }
                    }

                    if(sum%k==0) cnt++;   
                }
            }
        }

        return cnt;
    }
};