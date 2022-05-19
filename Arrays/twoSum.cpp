/*
leetcode link - https://leetcode.com/problems/two-sum/
*/

    //T.C=O(N),S.C=O(N)
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int> a;
        int i;
        for( i=0;i<nums.size();i++){
            if(a.count(target-nums[i])){
             break;
            }
            a[nums[i]]=i;
        }
        
        return {a[target-nums[i]],i};
    }
