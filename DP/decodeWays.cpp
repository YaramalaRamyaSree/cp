/*
leetcode link - https://leetcode.com/problems/decode-ways/
*/

//T.C=O(N)  //Bottom up
class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0')
            return 0;
        int n=s.length();
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<n+1;i++){
            int a=s[i-1]-'0';
            if(a!=0)
                dp[i]=dp[i-1];
            if(s[i-2]=='1'||(s[i-2]=='2'&&a<7))
                    dp[i]=dp[i]+dp[i-2];
        }
        return dp[n];
    }
};
