/*
gfg link - https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1
*/

//T.C=O(n*m) S.C=O(n*m)
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
       vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       int ans=0;
       for(int i=1;i<=n;i++){
           for(int j=1;j<=m;j++){
               if(S1[i-1]==S2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                ans=max(ans,dp[i][j]);
           }
       }
       return ans;
    }
