/*
gfg link - https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
*/

//T.C=O(N*SUM) S.C=O(N*SUM)
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
        for(int i=0;i<n;i++) dp[i][0]=1;
        if(arr[0]<=sum) dp[0][arr[0]]=1;
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool not_take=dp[i-1][j];
                bool take=false;
                if(arr[i]<=j) take=dp[i-1][j-arr[i]];
                dp[i][j]=not_take|take;
            }
        }
        return dp[n-1][sum];
    }
