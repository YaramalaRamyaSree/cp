/*
leetcode link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/

//Recursion T.C=O(2^N) S.C=O(N)
    int helper(int ind,int buy,vector<int>prices,int n){
        if(ind==n) return 0;
        int profit=0;
        if(buy){
            profit+=max(-prices[ind]+helper(ind+1,0,prices,n),0+helper(ind+1,1,prices,n));
        }
        else{
            profit+=max(prices[ind]+helper(ind+1,1,prices,n),0+helper(ind+1,0,prices,n));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        return helper(0,1,prices,n);
    }

//Memoization  T.C=O(N*2) S.C=O(N)+o(n*2)
    int helper(int ind,int buy,vector<int>prices,int n,vector<vector<int>>&dp){
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=0;
        if(buy){
            profit+=max(-prices[ind]+helper(ind+1,0,prices,n,dp),0+helper(ind+1,1,prices,n,dp));
        }
        else{
            profit+=max(prices[ind]+helper(ind+1,1,prices,n,dp),0+helper(ind+1,0,prices,n,dp));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(0,1,prices,n,dp);
    }

//Tabulation T.C=O(N*2) S.C=O(N*2)
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        dp[n][0]=dp[n][1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    profit+=max(-prices[ind]+dp[ind+1][0],0+dp[ind+1][1]);
                }
                else{
                   profit+=max(prices[ind]+dp[ind+1][1],0+dp[ind+1][0]);
                }
                dp[ind][buy]=profit;
            }
        }
        return dp[0][1];
    }

//Space Optimisation  T.C=O(N*2) S.C=O(2)
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>prev(2,0);
        prev[0]=prev[1]=0;
        for(int ind=n-1;ind>=0;ind--){
            vector<int>curr(2,0);
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    profit+=max(-prices[ind]+prev[0],0+prev[1]);
                }
                else{
                   profit+=max(prices[ind]+prev[1],0+prev[0]);
                }
                curr[buy]=profit;
            }
            prev=curr;
        }
        return prev[1];
    }
