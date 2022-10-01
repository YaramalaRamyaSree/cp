/*
gfg link - https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
*/

//T.C=O(N^3) S.C=O(N^2)
//Memoization
class Solution{
public:
    
    int helper(int i,int j,int arr[],vector<vector<int>>&dp){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int ind=i;ind<j;ind++){
            int temp=helper(i,ind,arr,dp)+helper(ind+1,j,arr,dp)+(arr[i-1]*arr[ind]*arr[j]);
            mini=min(mini,temp);
        }
        return dp[i][j]=mini;
    }


    int matrixMultiplication(int N, int arr[])
    {
       
      vector<vector<int>>dp(N,vector<int>(N,-1));
      return  helper(1,N-1,arr,dp);
      
    }
};
