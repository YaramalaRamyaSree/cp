/*
gfg link - https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1
*/

//recursion
    typedef long long int ll;
    ll mod=1000000007;
    ll helper (string s,int i,int j){
        if(i==j) return 1;
        if(i>j) return 0;
        ll count=0;
        if(s[i]==s[j]){
            count=(1+helper(s,i,j-1)+helper(s,i+1,j))%mod;
        }
        else
            count=(helper(s,i,j-1)+helper(s,i+1,j)-helper(s,i+1,j-1))%mod;
        return count;
    }
    long long int  countPS(string str)
    {
       return helper(str,0,str.size()-1);
    }

//Memoization
    typedef long long int ll;
    ll mod=1000000007;
    ll helper (string s,int i,int j,vector<vector<ll>>&dp){
        if(i==j) return dp[i][j]=1;
        if(i>j) return dp[i][j]=0;
        if(dp[i][j]!=-1) return dp[i][j];
        ll count=0;
        if(s[i]==s[j]){
            count=(1+helper(s,i,j-1,dp)+helper(s,i+1,j,dp))%mod;
        }
        else
            count=(helper(s,i,j-1,dp)+helper(s,i+1,j,dp)-helper(s,i+1,j-1,dp))%mod;
        return dp[i][j]=count;
    }
    long long int  countPS(string str)
    {
       int n=str.size();
       vector<vector<ll>>dp(n,vector<ll>(n,-1));
       return helper(str,0,n-1,dp);
    }

//Tabulation 
    typedef long long int ll;
    ll mod=1000000007;

    long long int  countPS(string s)
    {
       int n=s.size();
       ll dp[n][n];
       for(int g=0;g<n;g++){
           for(int i=0,j=g;j<n;i++,j++){
               if(g==0) dp[i][i]=1;
               else if(g==1) dp[i][j]=(s[i]==s[j])?3:2;
               else {
                    if(s[i]==s[j]){
                        dp[i][j]=((1+dp[i][j-1]%mod)%mod+dp[i+1][j]%mod)%mod;
                    }
                    else
                        dp[i][j]=((dp[i][j-1]%mod+dp[i+1][j]%mod)%mod-dp[i+1][j-1]%mod)%mod;
               }
           }
       }
       return (mod+dp[0][n-1])%mod;
    }
