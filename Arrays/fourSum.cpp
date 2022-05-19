/*
leetcode link - https://leetcode.com/problems/4sum/
*/
  
    //logic - used 2 pointers and twosum logic and eliminated using set for quadruplets bysorting array intially and take care of duplicates .
    //T.C=O(N^3),S.C=O(1) we did not use any extra space as vector is to be returned for sure .

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      
        int n=nums.size();
      
        sort(nums.begin(),nums.end());
      
        vector<vector<int>> quadruplets;
      
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
              
                int rem=target-(nums[i]+nums[j]);
                int left=j+1;
                int right=n-1;
              
                while(left<right){
                  
                int twosum=nums[left]+nums[right];
                  
                if(twosum>rem) right--;
                  
                else if(twosum<rem) left++;
                  
                else{
                    vector<int>temp(4,0);
                    temp[0]=nums[i];
                    temp[1]=nums[j];
                    temp[2]=nums[left];
                    temp[3]=nums[right];
                    quadruplets.push_back(temp);
                    
                    while(left<right && nums[left]==temp[2]) ++left;
                  
                    while(left<right && nums[right]==temp[3]) --right;
                }
                  
                }
                while(j+1<n && nums[j+1]==nums[j])++j;
            }
            while(i+1<n && nums[i+1]==nums[i])  ++i;
        }
        return quadruplets;
    }
