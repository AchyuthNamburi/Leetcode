class Solution {
public:
    vector<vector<int>> dir = {
        {1,1},{-1,-1},{1,0},{0,1},{-1,0},{0,-1},{-1,1},{1,-1}
    };

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // BFS returns the shortest Path ---don't worry and excite !
       int n = grid.size();
        int x_src = 0,y_src = 0;
        int x_tar = n-1,y_tar = n-1;

        if(grid[x_src][y_src] != 0 || grid[x_tar][y_tar] != 0) return -1;
        vector<vector<int>> visited(n,vector<int>(n,0));

        queue<pair<int,int>> q;
        q.push({x_src,y_src});

        int steps=1;

        while(!q.empty()){
            int size=q.size();

            for(int i=0;i<size;i++){
                auto [curr_x,curr_y]=q.front();
                q.pop();

                if(curr_x==x_tar && curr_y==y_tar) return steps;

                for(auto it:dir){
                    int new_x=curr_x+it[0];
                    int new_y=curr_y+it[1];

                    if(new_x>=0 && new_x<n && new_y>=0 && new_y<n && grid[new_x][new_y]==0 && !visited[new_x][new_y]){
                        visited[new_x][new_y]=1;
                        q.push({new_x,new_y});
                    }
                }
            }
            steps++;
        }
            
        return -1;
    }
};