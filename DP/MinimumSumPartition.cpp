/*
gfg link - https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/0
*/

//T.C=O(N*TOTAL_SUM) S.C=O(N*TOTAL_SUM)
	int minDifference(int arr[], int n)  { 
	    int sum=accumulate(arr,arr+n,0);
	    int mini=sum;
	    vector<vector<bool>>dp(n+1,vector<bool>(sum+1,0));
	    for(int i=0;i<=n;i++) dp[i][0]=1;
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=sum;j++){
	            bool not_take=dp[i-1][j];
	            bool take=false;
	            if(arr[i-1]<=j) take=dp[i-1][j-arr[i-1]];
	            dp[i][j]=not_take|take;
	        }
	    }
	    for(int s=1;s<=sum/2;s++){
	        if(dp[n][s])  mini=min(mini,sum-s*2);
	    }
	    return mini;
	} 
