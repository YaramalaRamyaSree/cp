/*
 coding ninjas link - https://www.codingninjas.com/codestudio/problems/frog-jump_3621012
*/
 

//Recursive -T.C=O(2^n) S.C=O(N)-stack space
int f(int n, vector<int> &heights)
{
   if(n==0) 
       return 0;
   int left = abs(heights[n-1]-heights[n])+f(n-1,heights);
    int right=INT_MAX;
   if(n>1)
       right=abs(heights[n-2]-heights[n])+f(n-2,heights);
   return min(left,right);
}
int frogJump(int n, vector<int> &heights){
    return  f(n-1,heights);
}

//Memoization -T.C=O(N) S.C=O(N)+O(N)-dp+stack space
int f(int n, vector<int> &heights, vector<int>&dp)
{
   if(n==0) 
       return 0;
   if(dp[n]!=-1) 
       return dp[n];
   int left = abs(heights[n-1]-heights[n])+f(n-1,heights,dp);
    int right=INT_MAX;
   if(n>1)
       right=abs(heights[n-2]-heights[n])+f(n-2,heights,dp);
   return dp[n]=min(left,right);
}
int frogJump(int n, vector<int> &heights){
    vector<int>dp(n,-1);
    return  f(n-1,heights,dp);
}

//Tabulation T.C=O(N) S.C=O(N)-dp space
int frogJump(int n, vector<int> &heights){
    vector<int>dp(n,0);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int left = abs(heights[i-1]-heights[i])+dp[i-1];
        int right=INT_MAX;
        if(i>1)
           right=abs(heights[i-2]-heights[i])+dp[i-2];
        dp[i]=min(left,right);
    }
    return dp[n-1];
}

//Space Optimization T.C=O(N) S.C=O(1)
int frogJump(int n, vector<int> &heights){
    int prev=0,prev2=0;
    for(int i=1;i<n;i++){
        int left = abs(heights[i-1]-heights[i])+prev;
        int right=INT_MAX;
        if(i>1)
           right=abs(heights[i-2]-heights[i])+prev2;
        int curr=min(left,right);
        prev2=prev;
        prev=curr;
    }
    return prev;
}
