/*
leetcode link - https://leetcode.com/problems/sudoku-solver/
*/

    //T.C=O(9^(N*N)) //S.C=O(1) We are refilling board may be auxilary space will be at max o(n+n)
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    
                    for(char c='1';c<='9';c++){
                       if(isValid(board,i,j,c))
                       {
                           board[i][j]=c;
                           if(solve(board)) return true;
                           else board[i][j]='.';
                       }   
                    }
                //if none of char is suited for board[i][j] return false
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>&board,int row,int col,char c){
        for(int i=0;i<9;i++){
            //check row 
            if(board[row][i]==c) return false;
            
            //check column
            if(board[i][col]==c) return false;
            
            //check box
            if(board[3*(row/3) + i/3][3*(col/3)+i%3]==c) return false;
        }
        return true;
    }
