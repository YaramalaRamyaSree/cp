/*
gfg link - https://practice.geeksforgeeks.org/problems/number-of-distinct-subsequences0909/0
*/

//T.C=O(N) S.C=O(N)
	int distinctSubsequences(string s)
	{
	    int mod=1000000007;
	    int n=s.size();
	    int dp[n+1];
	    dp[0]=1;dp[1]=2;
	    int seen[26];
	    memset(seen,-1,sizeof(seen));
	    seen[s[0]-'a']=0;
	    for(int i=2;i<=n;i++){
	        dp[i]=(dp[i-1]*2)%mod;
	        if(seen[s[i-1]-'a']!=-1)
	            dp[i]=(dp[i]%mod-dp[seen[s[i-1]-'a']]%mod+mod)%mod;
	        seen[s[i-1]-'a']=i-1;
	    }
	    return dp[n];
	}
	/*
  Example
	gfg
	
	empty
	
	empty
	empty+g
	
	empty
	empty+g
	empty+f
	empty+g+f
	
    empty //repeating for g (some intersection we have to delete (8-1)=7)
	empty+f
	empty+g+f
	empty+g
	empty+g+g
	empty+f+g
	empty+g+f+g
	
	*/
