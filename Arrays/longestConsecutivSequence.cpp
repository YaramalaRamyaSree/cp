/*
leetcode link - https://leetcode.com/problems/longest-consecutive-sequence/
*/

    //T.C=O(N)+O(N)+O(N)~O(N),S.C=O(N)
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        unordered_set<int> hashSet;
        
        //inserting to set
        for(auto it:nums)
            hashSet.insert(it);
        
        //maximum-consecutive-streak finding 
        
        int maxConseq=1,currnum,conseq;
        
        for(int i=0;i<nums.size();i++){
        
            if(!hashSet.count(nums[i]-1)){
                currnum=nums[i]+1;
                conseq=1;
            
                while(hashSet.count(currnum)){
                currnum+=1;
                conseq+=1;
                }
            
                maxConseq=max(conseq,maxConseq);
           }    
        }
    
        return maxConseq;
    }
