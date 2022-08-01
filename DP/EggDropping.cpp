/*
gfg link - https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1
*/

/*IDEA-
1.if we have 1 egg k floors we need k steps  
2.Here we need to find minimum of (maximum steps in worst case) 
3.We don't care about egg (it may or may not break at all ) we just need to find min of max steps to tell whether egg breaks at f floor and f is not known to us 
IDEA is to find at every step possibilities are egg break and not break (IF  at ith floor egg 
                                                                          BREAK -  we will have n-1 eggs and i-1 floors f(n-1,i-1
                                                                         NOT BREAK - we will have to find problem of n eggs and k-i floors f(n,k-i)  ).
*/

//Recursion -T.C=O(2^(n*(k^2))) S.C=O(n)
    int f(int n,int k){
        if(n==1) return k;
        if(k==0) return 0;
        int mini=INT_MAX;
        for(int i=1;i<=k;i++){
            int Break=f(n-1,i-1,dp);
            int notBreak=f(n,k-i,dp);
            int maxi =max(Break,notBreak);
            mini=min(mini,1+maxi);
        }
        return mini;
    }
    int eggDrop(int n, int k) 
    {
        return f(n,k);
    }

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
