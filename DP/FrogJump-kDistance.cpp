//Recursive T.C=O(k^n) S.C=O(N) 
int f(int n,int k, vector<int> &heights)
{
   if(n==0) 
       return 0;
  int mmsteps=INT_MAX;
  for(int i=0;i<k;i++){
    if(n-i>=0){
     int jump = abs(heights[n-i]-heights[n])+f(n-i,k,heights);
     mmsteps=min(mmsteps,jump);
    }
  }
   return mmsteps;
}
int frogJump(int n, int k,vector<int> &heights){
    return  f(n-1,k,heights);
}
//MemoizationT.C=O(k*n) S.C=O(N)+O(N) 
int f(int ind, vector<int>& height, vector<int>& dp, int k){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int mmSteps = INT_MAX;
    for(int j=1;j<=k;j++){
        if(ind-j>=0){
            int jump = abs(height[ind]- height[ind-j])+f(ind-j, height, dp, k);
            mmSteps= min(jump, mmSteps);
        }
    }
    return dp[ind]= mmSteps;
}
int frogJump(int n, vector<int>& height , int k){
    vector<int> dp(n,-1);
    return f(n-1, height, dp, k);
}
//Tabulation T.C=O(k*n) S.C=O(N) 
int f(int n, vector<int>& height, vector<int>& dp, int k){
    dp[0]=0;
    for(int i=1;i<n;i++){
        int mmSteps = INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jump = dp[i-j]+ abs(height[i]- height[i-j]);
                mmSteps= min(jump, mmSteps);
            }
        }
        dp[i]= mmSteps;
    }
    return dp[n-1];
}
int frogJump(int n, vector<int>& height , int k){
    vector<int> dp(n,-1);
    return f(n, height, dp, k);
}
//Space Otmization  T.C=O(k*n) S.C=O(K) which is O(N) in worst case so need not do this optimization . 

