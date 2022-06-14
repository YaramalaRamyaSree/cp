/*
leetcode link - https://leetcode.com/problems/permutations/
*/

   //T.C=O(n!*n) S.C=O(N) - freq array 
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++) freq[i]=0;
        find(freq,nums,v,ans);
        return ans;
    }
    
    void find(int freq[],vector<int>& nums,vector<int>v,vector<vector<int>> &ans){
        
        if(v.size()==nums.size())
            ans.push_back(v);
        
        for(int i=0;i<nums.size();i++){
            
            if(freq[i]==0){
                v.push_back(nums[i]);
                freq[i]=1;
                find(freq,nums,v,ans);
                freq[i]=0;
                v.pop_back();
            }
            
        }
    }

  //OPTIMAL SOLUTION
  //T.C=O(N!*N) ,S.C=O(1)
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        find(0,nums,ans);
        return ans;
    }
    
    void find(int index,vector<int>& nums,vector<vector<int>> &ans){
        
        if(index==nums.size())
            ans.push_back(nums);
        
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            find(index+1,nums,ans);
            swap(nums[index],nums[i]);
        }
        
    }
