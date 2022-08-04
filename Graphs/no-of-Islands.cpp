/*
leetcode link - https://leetcode.com/problems/number-of-islands/
*/

      //T.C=O(N*M) S.C=O(N*M)
       void f(int i,int j,int n,int m,vector<vector<char>> &grid){
        if(i<0||i>=n||j<0||j>=m || grid[i][j]!='1') return ;
        grid[i][j]='2';
        f(i-1,j,n,m,grid);
        f(i,j-1,n,m,grid);
        f(i,j+1,n,m,grid);
        f(i+1,j,n,m,grid);
        return ;
        
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int n=grid.size(),m=grid[0].size();
        int islands=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    f(i,j,n,m,grid);
                    ++islands;
                }
            }
        }
        return islands;
    }
