/*
leetcode link - https://leetcode.com/problems/combination-sum-ii/
*/

    //T.C=O((2^n * k) + nlogn )
    //S.C=O(k*x)
    void findCombinations(int index, int target, int n, vector<int>&arr,vector<int>&ds,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(ds);
            return ;
        }
        
        for(int i=index;i<n;i++){
            if(i>index && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            ds.push_back(arr[i]);
            findCombinations(i+1,target-arr[i],n,arr,ds,ans);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        findCombinations(0,target,candidates.size(),candidates,ds,ans);
        return ans;
    }
