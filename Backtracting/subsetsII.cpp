/*
leetcode link  - https://leetcode.com/problems/subsets-ii/
*/

    //T.C=O(2^n*n),S.c=O(2^n)*O(k)

    void findSubsets(int index, int n,vector<int>& nums,vector<int>& ds, vector<vector<int>> &ans){
            ans.push_back(ds);
        for(int i=index;i<n;i++){
            if(i>index && nums[i]==nums[i-1] ) continue;
            ds.push_back(nums[i]);
            findSubsets(i+1,n,nums,ds,ans);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>ds;
        findSubsets(0,nums.size(),nums,ds,ans);
        return ans;
    }
