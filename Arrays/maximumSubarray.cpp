/*
leetcode link - https://leetcode.com/problems/maximum-subarray/
*/

    int maxSubArray(vector<int>& nums) {
        int sum=0,maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxi=max(maxi,sum);
            if(sum<0) sum=0;
        }
        return maxi;
    }
    
    // if we also want to print sub array
    // Approach 1  
    void SubarrayWithMaxSum(vector<int>& nums)
    {

        int endIndex, sum = nums[0];
        int maxi = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            sum = max(nums[i],nums[i] + sum);
            if (sum > maxi) {
                maxi = sum;
                endIndex = i;
            }
        }

        int startIndex = endIndex;

        while (startIndex >= 0) {
            maxi -= nums[startIndex];
            if (maxi == 0)
                break;
            startIndex--;
        }

        for (int i = startIndex;i <= endIndex; ++i) 
            cout << nums[i] << " ";

    }
  
     //  Approach 2 

     /*  
         Use 3 vraibles startindex,endindex,and globalStartindex
         
         For each element in the array starting from index (say i) , update sum = nums[i] and startIndex = i if nums[i] > nums[i] + sum . Else only update sum = sum+nums[i].
         
         if sum > maxi  update maxi=sum and  globalStartindex to startindex , endindex = i .
         
         now iterate from globalStart to end index to print subarray .
     */
