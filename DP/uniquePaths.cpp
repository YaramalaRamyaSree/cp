/*
coding ninjas - https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470
*/

//Recursion -T.C=O(2^(m*n)) S.C=O(m)
int f(int row,int col){
    if(row==0 && col==0) return 1;
    if(row<0 || col<0) return 0;
    int up =f(row-1,col);
    int left=f(row,col-1);
    return up+left;
}
int uniquePaths(int m, int n) {
	return f(m-1,n-1);
}

//Memoization -T.C=O(M*N) S.C=O(M*N)+O(M)
int f(int row,int col,vector<vector<int>>&dp){
    if(row==0 && col==0) return 1;
    if(row<0 || col<0) return 0;
    if(dp[row][col]!=-1) return dp[row][col];
    int up =f(row-1,col,dp);
    int left=f(row,col-1,dp);
    return dp[row][col]=up+left;
}
int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m,vector<int>(n,-1));
	return f(m-1,n-1,dp);
}

//Tabulation -T.C=O(N*M) S.C=O(N*M)
int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m,vector<int>(n,0));
    for(int row=0;row<m;row++){
        for(int col=0;col<n;col++){
            if(row==0 && col==0 ) {
                dp[row][col]=1;
                continue;}
            int up=0,left=0;
            if(row>0) up =dp[row-1][col];
            if(col>0) left =dp[row][col-1];
            dp[row][col]=up+left;
        }
    }

//Space Optimization -T.C=O(N*M) S.C=O(N)
  int uniquePaths(int m, int n) {
    vector<int>prev(n,0);
    for(int row=0;row<m;row++){
        vector<int>curr(n,0);
        for(int col=0;col<n;col++){
            if(row==0 && col==0 ) {
                curr[col]=1;
                continue;}
            int up=0,left=0;
            if(row>0) up =prev[col];
            if(col>0) left =curr[col-1];
            curr[col]=up+left;
        }
        prev=curr;
    }
	return prev[n-1];
}
