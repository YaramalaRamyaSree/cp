/*
leetcode link - https://leetcode.com/problems/split-array-into-consecutive-subsequences/
*/

//hashing+greedy T.C=O(N) S.C=O(N) 
//firstly maintain frequency map of array elements and then initialize vacancy map ,
//iterate given array see if its possible to make partition of three and  if its possible, 
//fourth one add in vacancy if needed we wil use later for next group or same group 
/*
      eg: nums=[1,2,3,3,4,4,5,5]
      123 have in array add 4 in vacancy 
      2 freq =0
      3 freq=1 but not in vacancy so make 345  add 6 in vacancy
      3 freq=0
      4 freq=0
      4 freq=1 but its there in vacancy so remove 4 vacancy , and add 5 in vacancy 
      5 freq=0 but 5 in vacancy so remove 5 in vacnacy 
      end of array  
      So succesfully formed [1,2,3,4,5],[3,4,5] groups */

    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>freq;
        unordered_map<int,int>vacancy;
        int n=nums.size();
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            if(freq[nums[i]]==0){
                continue;
            }
            else if (vacancy[nums[i]]){
                vacancy[nums[i]]--;
                freq[nums[i]]--;
                vacancy[nums[i]+1]++;
            }
            else if(freq[nums[i]]>0 && freq[nums[i]+1]>0 && freq[nums[i]+2]>0){
                freq[nums[i]]--;
                freq[nums[i]+1]--;
                freq[nums[i]+2]--;
                vacancy[nums[i]+3]++;
            }
            else return false;
        }
        return true;
    }
