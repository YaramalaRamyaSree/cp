/*
leetcode link - https://leetcode.com/problems/combination-sum/
*/

   //T.C=(2^t *k) =k is avg len of ds pushed into ans,2^t calls  we may end doing in worst case , t may be unpredictable
   //S.C=O(k*x),x is no of combinations in ans and k is avg length + call stack 

    void findCombinations(int i,int target,vector<int>& arr, int n,vector<int>&ds, vector<vector<int>>&ans){
        if(i==n){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(arr[i]<=target){
            ds.push_back(arr[i]);
            findCombinations(i,target-arr[i],arr,n,ds,ans);
            ds.pop_back();
        }
        findCombinations(i+1,target,arr,n,ds,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        findCombinations(0,target,candidates,candidates.size(),ds,ans);
        return ans;
    }
