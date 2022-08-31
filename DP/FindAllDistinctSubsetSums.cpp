/*
gfg link - https://practice.geeksforgeeks.org/problems/find-all-distinct-subset-or-subsequence-sums4424/1
*/

//Tabulation -bottom up T.C=O(n*sum) S.C=O(n*sums)
	vector<int> DistinctSum(vector<int>arr){
	    int n=arr.size();
	    int target=0;
	    for(int i=0;i<n;i++)
	        target+=arr[i];
	   vector<vector<bool>>dp(n,vector<bool>(target+1,0));
	   for(int i=0;i<n;i++) dp[i][0]=true;
	   if(arr[0]<=target) dp[0][arr[0]]=true;
	   for(int i=1;i<n;i++){
	       for(int s=1;s<=target;s++){
	           bool not_take=dp[i-1][s];
	           bool take=false;
	           if(arr[i]<=s) take+=dp[i-1][s-arr[i]];
	           dp[i][s]=take|not_take;
	       }
	   }
	   vector<int>v;
	   for(int i=0;i<=target;i++){
	       if(dp[n-1][i]==true) v.push_back(i); 
	   }
	   return v;
	}
