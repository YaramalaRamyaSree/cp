/*
leetcode link - https://leetcode.com/problems/unique-paths/
*/

// DP solution -improvemnet to brute force recursion solution
//T.C=O(M*N),S.C=O(M*N)

    int countpaths(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i>=m || j>=n) return 0;
        if(i==m-1&&j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=countpaths(i+1,j,m,n,dp)+countpaths(i,j+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return countpaths(0,0,m,n,dp);
    }

/*
Combinatorics solution
why?
because of two observations 
in every path there is m+n-2 steps
in every path there are m-1 , n-1  right and down steps 
hence we can choose any order of m-1 steps or we can choose any order of n-1 steps 
*/
//T.C=O(M-1) OR O(N-1) based on implementation ,S,C=O(1)

    int uniquePaths(int m, int n) {
        int N = m+n-2;
        int r = m-1;
        double res=1;
        for(int i=1;i<=r;i++){
            res=res*(N-r+i)/i;
        }
        return (int)res;
    }
