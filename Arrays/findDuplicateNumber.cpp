/*
leetcode link - https://leetcode.com/problems/find-the-duplicate-number/
*/

    int findDuplicate(vector<int>& nums) {
      
        //both slow and fast start at same point 
      
         int slow =nums[0],fast=nums[0];
        
         do{
             slow=nums[slow];
             fast=nums[nums[fast]];
         }while(slow!=fast);
         
        /* 
        letslow,fast  met at some point c first time  ,surely slow moved a means fast moved 2a from start till c.  
        hence distance from start to slow is equal to cycle length
        */
      
        //pacca second collision is duplicate number .
      
        fast=nums[0];
      
        // now distance to duplicate from fast is equal to distance from slow to duplicate. 
      
        while(slow!=fast){
             slow=nums[slow];
             fast=nums[fast];
         }
        
        return slow;
    }
