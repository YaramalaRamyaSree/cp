/*
leetcode link - https://leetcode.com/problems/n-queens/
*/

    //T.C=O(N!*N) T(n)=n+n*T(n-1)
    //S.C=O(n^2)
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++) board[i]=s;
        find(0,n,board,ans);
        return ans;
    }
    
     void find(int col,int n,vector<string>&board,vector<vector<string>>&ans){
        if(col==n){
            ans.push_back(board);
        }
        
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                find(col+1,n,board,ans);
                board[row][col]='.';
            }
        }
    }
    
    bool isSafe(int row,int col,vector<string>&board,int n){
        int duprow=row;
        int dupcol=col;
        //check for left row
        for(int i=col-1;i>=0;i--){
            if(board[row][i]=='Q') return false;
        }
        //check for upper diagonal 
        while(row>0&&col>0){
            if(board[--row][--col]=='Q') return false;
        }
        //check for lower diagonal 
        row=duprow;col=dupcol;
        while(row<n-1&&col>0){
            if(board[++row][--col]=='Q') return false;
        }
        return true;
    }


    //OPTIMISING isSafe function  from o(n) to o(1) by hashing -extra space added of 3O(n). 
    //T.C=O(N!*N) T(n)=n+n*T(n-1)
    //S.C=O(n^2)
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++) board[i]=s;
        vector<int> leftrow(n,0),upperDiagonal(2*n-1,0),lowerDiagonal(2*n-1,0);
        find(0,n,board,ans,leftrow,upperDiagonal,lowerDiagonal);
        return ans;
    }
    
    void find(int col,int n,vector<string>&board,vector<vector<string>>&ans,vector<int>&leftrow,vector<int>&upperDiagonal,vector<int>&lowerDiagonal){
        if(col==n){
            ans.push_back(board);
        }
        
        for(int row=0;row<n;row++){
            if(leftrow[row]!=1&&upperDiagonal[n-1+(col-row)]!=1&&lowerDiagonal[row+col]!=1){
                leftrow[row]=1;
                upperDiagonal[n-1+(col-row)]=1;
                lowerDiagonal[row+col]=1;
                board[row][col]='Q';
                find(col+1,n,board,ans,leftrow,upperDiagonal,lowerDiagonal);
                board[row][col]='.';
                leftrow[row]=0;
                upperDiagonal[n-1+(col-row)]=0;
                lowerDiagonal[row+col]=0;
            }
        }
    }
    
