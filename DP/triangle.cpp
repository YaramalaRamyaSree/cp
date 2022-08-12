/*
coding ninjas link - https://www.codingninjas.com/codestudio/problems/triangle_1229398
*/

// here we know starting point but do not know ending so start with 0,0

//Recursion T.C=2^(m*n) S.C=O(rows)
int f(int i,int j,vector<vector<int>>& triangle,int n){
  if(i>n
    if(i==n-1)return triangle[i][j];
    int d=triangle[i][j]+f(i+1,j,triangle,n);
    int dg=triangle[i][j]+f(i+1,j+1,triangle,n);
    return min(d,dg);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	return f(0,0,triangle,n);
}

//Memoization T.C=O(M*N) S.C=O(M*N)+O(ROWS)
int f(int i,int j,vector<vector<int>>& triangle,int n,vector<vector<int>>& dp){
    if(i==n)return triangle[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int d=triangle[i][j]+f(i+1,j,triangle,n,dp);
    int dg=triangle[i][j]+f(i+1,j+1,triangle,n,dp);
    return min(d,dg);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return f(0,0,triangle,n,dp);
}

//Tabulation T.C=O(M*N) S.C=O(M*N)
int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++){ dp[n-1][i]=triangle[n-1][i];}
    for(int i=n-2;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            int d=triangle[i][j];
                if(i+1<n) d+=dp[i+1][j];
                else d+=1e8;
            int dg=triangle[i][j];
               if(j+1<n&&i+1<n) dg+=dp[i+1][j+1];
                else d+=1e8;
              dp[i][j]=min(d,dg);
        }
    }
    return dp[0][0];
}
     
//Space Optimization T.C=O(M*N) S.C=O(cols)
int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<int>prev(n,0);
    for(int i=0;i<n;i++){ prev[i]=triangle[n-1][i];}
    for(int i=n-2;i>=0;i--){
        vector<int>curr(n,0);
        for(int j=n-1;j>=0;j--){
            int d=triangle[i][j];
                if(i+1<n) d+=prev[j];
                else d+=1e8;
            int dg=triangle[i][j];
               if(j+1<n&&i+1<n) dg+=prev[j+1];
                else d+=1e8;
              curr[j]=min(d,dg);
        }
        prev=curr;
    }
    return prev[0];
}
