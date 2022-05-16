/*
leetcode link - https://leetcode.com/problems/merge-sorted-array/
*/

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1=m-1,p2=n-1,idx=m+n-1;
        while(p2>=0){
            if(p1>=0 && nums1[p1]>nums2[p2] ){
                nums1[idx]=nums1[p1];
                idx--;
                p1--;
            }
            else{
                nums1[idx]=nums2[p2];
                idx--;
                p2--;
            }
        }
        
    }
