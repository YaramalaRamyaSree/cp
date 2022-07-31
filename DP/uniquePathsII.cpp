/*
coding ninjas - https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241
*/

//Recursion -T.C=O(2^(N*M)) S.C=O(N)
int mod=1000000007;
int f(int n,int m,vector<vector<int>> mat){
    if(n==0 && m==0) 
        return 1;
    if(n<0 || m<0) 
        return 0;
    if(mat[n][m]==-1)
        return 0; 
    int up=f(n-1,m,mat)%mod;
    int left=f(n,m-1,mat)%mod;
    return (up+left)%mod;
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
    return f(n-1,m-1,mat);
}

//Memoization -T.C=O(N*M) S.C=O(N*M)+O(N)
int mod=1000000007;
int f(int n,int m,vector<vector<int>> mat,vector<vector<int>> &dp){
    if(n==0 && m==0) 
        return 1;
    if(n<0 || m<0) 
        return 0;
    if(mat[n][m]==-1)
        return 0; 
    if(dp[n][m]!=-1) return dp[n][m];
    int up=f(n-1,m,mat,dp)%mod;
    int left=f(n,m-1,mat,dp)%mod;
    return dp[n][m]=(up+left)%mod;
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return f(n-1,m-1,mat,dp);
}

//Tabulation -T.C=O(N*M) S.C=O(N*M)
int mod=1000000007;
int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0) {
                dp[i][j]=1;
                continue;}
            if(mat[i][j]==-1){
                dp[i][j]=0;
                continue;
            } 
            int up=0,left=0;
            if(i>0)
                up=dp[i-1][j]%mod;
            if(j>0)
                left=dp[i][j-1]%mod;
            dp[i][j]=(up+left)%mod;
        }
    }
    return dp[n-1][m-1];
}

//Space Otimization - T.C=O(N*M) S.C=O(M)=O)(COLUMNS)
int mod=1000000007;
int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
    vector<int>prev(m,0);
    for(int i=0;i<n;i++){
        vector<int>curr(m,0);
        for(int j=0;j<m;j++){
            if(i==0 && j==0) {
                curr[j]=1;
                continue;}
            if(mat[i][j]==-1){
                curr[j]=0;
                continue;
            } 
            int up=0,left=0;
            if(i>0)
                up=prev[j]%mod;
            if(j>0)
                left=curr[j-1]%mod;
            curr[j]=(up+left)%mod;
        }
        prev=curr;
    }
    return prev[m-1];
}
