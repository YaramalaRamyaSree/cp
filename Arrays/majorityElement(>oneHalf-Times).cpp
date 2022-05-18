/*
leetcode link - https://leetcode.com/problems/majority-element/
*/
//moore voting algorithm

    // T.C=O(N),S.C=O(1)
    int majorityElement(vector<int>& nums) {
        //m=majority element
        int count=0,m;
        
        for(int num :nums){
            if(count==0){
                count=1;
                m=num;
            }
            else if(m==num)
                count++;
            else
                count--;
        }
        return m;
    }
