class Solution {
public:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    void bfs(int i,int j,vector<vector<char>>& board){
        int m=board.size();
        int n=board[0].size();

        queue<pair<int,int>> q;
        // push all the boundary safe cells 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || i==m-1 || j==0 || j==n-1) && (board[i][j]=='O')){
                    board[i][j]='#'; // mark them as safe
                     q.push({i,j});
                }
            }
        }
    
        while(!q.empty()){
            auto it =q.front();
            int x=it.first;
            int y=it.second;
            q.pop();

            for(int k=0;k<4;k++){
                int new_x=x+dir[k][0];
                int new_y=y+dir[k][1];

                if(new_x>=0 && new_x<m && new_y>=0 && new_y<n && board[new_x][new_y]=='O'){
                    q.push({new_x,new_y});
                    board[new_x][new_y]='#';
                }
            }

        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    bfs(i,j,board);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }
                else{
                    board[i][j]='X';
                }
            }
        }
    }
};