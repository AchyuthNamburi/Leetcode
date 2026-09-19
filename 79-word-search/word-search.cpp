class Solution {
public:
    vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1}};

    bool solve(int idx,int x,int y,string & word,vector<vector<char>>& board,vector<vector<int>>& visited){

        int m=board.size();
        int n=board[0].size();
        if(idx==word.size()) return true;

        for(int i=0;i<4;i++){
            int new_x=x+dir[i][0];
            int new_y=y+dir[i][1];

            if(new_x<m && new_x>=0 && new_y>=0 && new_y<n && !visited[new_x][new_y] && board[new_x][new_y]==word[idx]){
                visited[new_x][new_y]=1;
                if(solve(idx+1,new_x,new_y,word,board,visited)) return true;
                visited[new_x][new_y]=0; //BT
            }
        }

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        //BFS logic 
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    visited[i][j]=1;
                    if(solve(1,i,j,word,board,visited)) return true;
                    visited[i][j]=0; //BT
                }
            }
        }

        return false;
    }
};