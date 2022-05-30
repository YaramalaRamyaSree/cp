/*
leetcode link - https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

    //Two pointer approach 
    //T.C=O(N),S.C=O(1)
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }

    //Brute force is use hash map ordered and store all unique ele from array and 
    //after traversing whole array copy back elements from hashMap to array  return size of hashmap
    //T.C=O(NlogN(,S.C=O(N)
