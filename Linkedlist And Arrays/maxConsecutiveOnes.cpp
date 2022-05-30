/*
leetcode link - https://leetcode.com/problems/max-consecutive-ones/
*/

//T.C=O(N),S.C=O(1)
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0,maxcnt=0;
        for(auto i:nums){
            if(i) cnt++;
            else cnt=0;
            maxcnt=max(cnt,maxcnt);
        }
        return maxcnt;
    }
