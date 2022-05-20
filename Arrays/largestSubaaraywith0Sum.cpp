/*
gfg link - https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
*/

    //T.C=O(N) ,S.C=O(N)
    //Idea of prefix sum and hashmap 
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> hashMap;
        int sum=0,maxLength=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum==0)
                maxLength=i+1;
            else if(hashMap.find(sum)!=hashMap.end()){
                maxLength=max(maxLength,i-hashMap[sum]);
            }
            else
            hashMap[sum]=i;
            
           
        }
        return maxLength;
    }
