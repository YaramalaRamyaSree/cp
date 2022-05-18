/*
leetcode link - https://leetcode.com/problems/majority-element-ii/
*/

    //T.C=O(N),S.C=O(1)
    //Boyre moore voting algorithm

    vector<int> majorityElement(vector<int>& nums) {
      
        int num1=-1,num2=-1,count1=0,count2=0;
      
        for(auto num : nums){
            if(num==num1)
                count1++;
            else if(num==num2)
                count2++;
            else if(count1==0){
                num1=num;
                count1=1;
            } 
            else if(count2==0){
                num2=num;
                count2=1;
            }
            else{
                count1--;
                count2--;
            }
        }
      //check for both num1,num2 i.e whether to check their frequency is > N/3 .
      // Its needed doing check because its not mentioned in question that we get elements guarenteed.
        count1=count2=0;
      
        for(int num:nums){
            if(num1==num) count1++;
            else if(num2==num) count2++;
        }
      
        vector<int>v;
      
        if(count1>nums.size()/3) v.push_back(num1);
        if(count2>nums.size()/3) v.push_back(num2);
      
        return v;
    }
