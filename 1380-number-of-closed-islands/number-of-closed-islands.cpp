class Solution {
public:
    vector<vector<int>> dir={{-1,0},{0,-1},{1,0},{0,1}};

    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> visited(m,vector<int>(n,0));

        
        int cnt=0;
        

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (grid[i][j] == 0 && !visited[i][j]) {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j]=1;
                    bool closed=true;

                    while(!q.empty()){
                        auto curr=q.front();
                        q.pop();
                        int x=curr.first;
                        int y=curr.second;

                        if(x==0 || x==m-1 || y==0 || y==n-1){
                            closed=false;
                        }
                            for(int i=0;i<4;i++){
                                int new_x=x+dir[i][0];
                                int new_y=y+dir[i][1];

                                if(new_x>=0 && new_x<m && new_y>=0 && new_y<n && grid[new_x][new_y]==0 && !visited[new_x][new_y]){
                                    q.push({new_x,new_y});
                                    visited[new_x][new_y]=1;
                                }
                            }  
                    }
                    if(closed==true){
                        cnt++;
                    }
                }
            }  
        }

        return cnt;

    }
};