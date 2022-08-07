/*
leetcode link - https://leetcode.com/problems/count-vowels-permutation/
*/

//Recursion sloved fom len=1 to len=n
   int f(int len,int vowel,int n,vector<vector<int>> &validnext){
        if(len==n) return 1;
        int count=0;
        for(auto it:validnext[vowel]){
            count+=f(len+1,it,n,validnext);
        }
        return count;
    }
    int countVowelPermutation(int n) {
        vector<vector<int>>validnext={{1},{0,2},{0,1,3,4},{2,4},{0}};
        int count=0;
        for(int i=0;i<5;i++){
           count+= f(1,i,n,validnext);
        }
        return count;
    }
    
//Mmeoization 
     int mod=1000000007;
     int f(int len,int vowel,int n,vector<vector<int>> &validnext,vector<vector<int>>&dp){
        if(len==n) return 1;
        if(dp[len][vowel]!=-1) return dp[len][vowel];
        int count=0;
        for(auto it:validnext[vowel]){
            count=(count%mod+f(len+1,it,n,validnext,dp)%mod)%mod;
        }
        return dp[len][vowel]=count;
    }
    int countVowelPermutation(int n) {
        vector<vector<int>>validnext={{1},{0,2},{0,1,3,4},{2,4},{0}};
        vector<vector<int>>dp(n,vector<int>(5,-1));
        int count=0;
        for(int i=0;i<5;i++){
           count= (count%mod+f(1,i,n,validnext,dp)%mod)%mod;
        }
        return count;
    }
    
//Tabulation bottom up len=n to len=1  as we did top down from len=1 to len=n
      int mod=1000000007;
        int countVowelPermutation(int n) {
            vector<vector<int>>validnext={{1},{0,2},{0,1,3,4},{2,4},{0}};
            vector<vector<int>>dp(n,vector<int>(5,0));
            for(int i=0;i<5;i++)dp[n-1][i]=1;
            for(int len=n-2;len>=0;len--){
                for(int vowel=0;vowel<5;vowel++){
                    dp[len][vowel]=0;
                    for(auto it:validnext[vowel]){
                        dp[len][vowel]=(dp[len][vowel]%mod+dp[len+1][it]%mod)%mod;
                    }
                }
            }
            int count=0;
            for(int i=0;i<5;i++){
                count=(count%mod+dp[0][i]%mod)%mod;
            }
        return count;
    }
    
//SpaceOptimization 
    int mod=1000000007;
        int countVowelPermutation(int n) {
            vector<vector<int>>validnext={{1},{0,2},{0,1,3,4},{2,4},{0}};
            vector<int>prev(5,0);
            for(int i=0;i<5;i++)prev[i]=1;
            for(int len=n-2;len>=0;len--){
                vector<int>curr(5,0);
                for(int vowel=0;vowel<5;vowel++){
                    curr[vowel]=0;
                    for(auto it:validnext[vowel]){
                        curr[vowel]=(curr[vowel]%mod+prev[it]%mod)%mod;
                    }
                }
                prev=curr;
            }
            int count=0;
            for(int i=0;i<5;i++){
                count=(count%mod+prev[i]%mod)%mod;
            }
        return count;
    }
