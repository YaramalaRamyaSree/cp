/*
leetcode link - https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
*/

//find len of number that is position of right most bit = 1+(log2(i)) --logic
//T.C=O(N)
    int concatenatedBinary(int n) {
        long long ans=0;
        int mod=1000000007;
        int i=1;
        while(i<=n){
            int len=1+int (log2(i));
            ans=((ans<<len)%mod+i)%mod;
            i++;
        }
        return ans;
    }
