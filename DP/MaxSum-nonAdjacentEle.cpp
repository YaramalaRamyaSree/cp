/*
coding ninjas - https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261
*/

//Recursive -T.C=O(2^n( S.C=O(N)
int f(int n, vector<int>&nums){
    if(n<0) return 0;
    if(n==0) return nums[0];
    int take=nums[n]+f(n-2,nums);
    int notTake=f(n-1,nums);
    return max(take,notTake);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    return f(n,nums);
}

//Memoization -T.C=O(N) S.C=O(N)+O(N)-stack space+dp space 
int f(int n, vector<int>&nums,vector<int>&dp){
    if(dp[n]!=-1) return dp[n];
    if(n<0) return 0;
    if(n==0) return nums[0];
    int take=nums[n]+f(n-2,nums,dp);
    int notTake=f(n-1,nums,dp);
    return dp[n]=max(take,notTake);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    vector<int>dp(n,-1);
    return f(n-1,nums,dp);
}

//Tabulation -T.C=O(N) S.C=O(N)-DP SPACE 
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    vector<int>dp(n,0);
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        int take=nums[i];
        if(i-2>=0) take+=dp[i-2];
        int notTake=dp[i-1];
        dp[i]=max(take,notTake);
    }
    return dp[n-1];
}

//Space Optimization -T.C=O(N) ,S.C=O(1)
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    int prev2=0;
    int prev=nums[0];
    for(int i=1;i<n;i++){
        int take=nums[i]+prev2;
        int notTake=prev;
        int curr=max(take,notTake);
        prev2=prev;
        prev=curr;
    }
    return prev;
}
