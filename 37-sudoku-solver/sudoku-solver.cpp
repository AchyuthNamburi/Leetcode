class Solution {
public:
    bool issafe(vector<vector<char>>& board,int row,int col,char ch){
        //check row
        for(int j=0;j<=9;j++){
            if(board[row][j]==ch){
                return false;
            }
        }
        //check col
        for(int i=0;i<9;i++){
            if(board[i][col]==ch){
                return false;
            }
        }
        //for 3*3 grid
        int startRow=(row/3)*3;
        int startCol=(col/3)*3;

        for(int i=startRow; i<startRow+3; i++){
            for(int j=startCol; j<startCol+3; j++){
                if(board[i][j]==ch){
                    return false;
                }
            }
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