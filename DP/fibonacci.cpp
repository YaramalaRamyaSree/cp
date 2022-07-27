//Recursion T.C=O(2^n),S.C=O(N)
int f(int n){
    if(n<=1) return n;
    return f(n-1) + f(n-2);
}

//Memoization T.C=O(N),S.C=O(N)+O(N)=DP+STACK SPACE
int f(int n, vector<int>& dp){
    if(n<=1) return n;
    
    if(dp[n]!= -1) return dp[n];
    return dp[n]= f(n-1,dp) + f(n-2,dp);
}

//Tabulation T.C=O(N) ,S.C=O(N)=DP NO STACK SPACE
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;cin>>n;
  vector<int> dp(n+1,-1);
  dp[0]= 0;
  dp[1]= 1;
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  cout<<dp[n];
  return 0;
}

//Space optimisation  T.C=O(N) S.C=O(1)
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin>>n;
  int prev2 = 0;
  int prev = 1;
  for(int i=2; i<=n; i++){
      int cur_i = prev2+ prev;
      prev2 = prev;
      prev= cur_i;
  }
  cout<<prev;
  return 0;
}
