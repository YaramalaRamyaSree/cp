/*
gfg link - https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1
*/

//Memoization -T.C=O(n*(k^2)) S.C=O(n*k)+O(n)
    int f(int n,int k,vector<vector<int>>&dp){
        if(n==1) return k;
        if(k==0) return 0;
        if(dp[n][k]!=-1) return dp[n][k];
        int mini=INT_MAX;
        for(int i=1;i<=k;i++){
            int Break=f(n-1,i-1,dp);
            int notBreak=f(n,k-i,dp);
            int maxi =max(Break,notBreak);
            mini=min(mini,1+maxi);
        }
        return dp[n][k]=mini;
    }
    int eggDrop(int n, int k) 
    {
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return f(n,k,dp);
    }

//Tabulation -T.C=O(n*(k^2)) S.C=O(n*k)
    int eggDrop(int n, int k) 
    {
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                if(i==1 || j==1){
                    dp[i][j]=j;
                    continue;}
                int mini=INT_MAX;
                for(int f=1;f<=j;f++){
                    int Break=dp[i-1][f-1];
                    int notBreak=dp[i][j-f];
                    int maxi =1+max(Break,notBreak);
                    mini=min(mini,maxi);
                }
                dp[i][j]=mini;
            }
        }
        
        return dp[n][k];
    }

//Space Optimization -T.C=O(n*(k^2)) S.C=O(k)
    int eggDrop(int n, int k) 
    {
        vector<int>prev(k+1,0);
        for(int i=1;i<=n;i++){
            vector<int>curr(k+1,0);
            for(int j=1;j<=k;j++){
                if(i==1 || j==1){
                    curr[j]=j;
                    continue;}
                int mini=INT_MAX;
                for(int f=1;f<=j;f++){
                    int Break=prev[f-1];
                    int notBreak=curr[j-f];
                    int maxi =1+max(Break,notBreak);
                    mini=min(mini,maxi);
                }
                curr[j]=mini;
            }
            prev=curr;
        }
        
        return prev[k];
    }
