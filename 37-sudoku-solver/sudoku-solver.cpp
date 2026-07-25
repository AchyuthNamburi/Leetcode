class Solution {
public:
    bool issafe(vector<vector<char>>& board,int row,int col,char ch){
        for (int i = 0; i < 9; i++) {
            // row check
            if (board[row][i] == ch) return false;

            // column check
            if (board[i][col] == ch) return false;

            // 3x3 sub-box check
            int r = 3 * (row / 3) + i / 3;  // crucial ..observe properly /
            int c = 3 * (col / 3) + i % 3;  //crucial ....observe properly %
            if (board[r][c] == ch) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                
                if(board[i][j]=='.'){
                    for(char ch='1'; ch<='9' ;ch++){
                        
                        if(issafe(board,i,j,ch)){
                            board[i][j]=ch; //assign
                            if(solve(board)) return true; //recurse
                            board[i][j]='.'; //backtrack
                        }
                    }
                    return false;
                }
            }
        }

        return true; //entire board is filled
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};