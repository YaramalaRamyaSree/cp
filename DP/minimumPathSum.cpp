/*
coding ninjas link - https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349
*/

//Recursive  T.C=O(2^(N*M)) S.C=O(N)
int f(int row,int col,vector<vector<int>> grid){
    if(row==0&&col==0) return grid[0][0];
    if(row <0 || col<0) return 1000000007;
    int up = grid[row][col]+f(row-1,col,grid);
    int left =grid[row][col]+f(row,col-1,grid);
    return min(up,left);
}
int minSumPath(vector<vector<int>> &grid) {
    return f(grid.size()-1,grid[0].size()-1,grid);
}

//Memoization T.C=O(N*M) S.C=O(N)+O(N*M)
int f(int row,int col,vector<vector<int>> grid,vector<vector<int>>&dp){
    if(row==0&&col==0) return grid[0][0];
    if(row <0 || col<0) return 1000000007;
    if(dp[row][col]!=-1) return dp[row][col];
    int up = grid[row][col]+f(row-1,col,grid,dp);
    int left =grid[row][col]+f(row,col-1,grid,dp);
    return dp[row][col]=min(up,left);
}
int minSumPath(vector<vector<int>> &grid) {
    vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
    return f(grid.size()-1,grid[0].size()-1,grid,dp);
}

//Tabulation T.C=O(N*M) S.C=O(N*M)
int minSumPath(vector<vector<int>> &grid) {
    vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(i==0 && j==0) {
                dp[i][j]=grid[0][0];
                continue;}
            int up=grid[i][j],left=grid[i][j];
            if(i>0)
                up+=dp[i-1][j];
            else up+=1000000007;
            if(j>0)
                left+=dp[i][j-1];
            else left+=1000000007;
            dp[i][j]=min(up,left);     
        }
    }
    return dp[grid.size()-1][grid[0].size()-1];
}

//Space Optimization T.C=O(N*M) S.C=O(M)
int minSumPath(vector<vector<int>> &grid) {
    vector<int>prev(grid[0].size(),0);
    for(int i=0;i<grid.size();i++){
        vector<int>curr(grid[0].size(),0);
        for(int j=0;j<grid[0].size();j++){
            if(i==0 && j==0) {
                curr[j]=grid[0][0];
                continue;}
            int up=grid[i][j],left=grid[i][j];
            if(i>0)
                up+=prev[j];
            else up+=1000000007;
            if(j>0)
                left+=curr[j-1];
            else left+=1000000007;
            curr[j]=min(up,left);     
        }
        prev=curr;
    }
    return prev[grid[0].size()-1];
}
