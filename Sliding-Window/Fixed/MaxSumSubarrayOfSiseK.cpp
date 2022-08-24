/*
gfg link - https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
*/

//T.C=O(N) S.C=O(1)
    long maximumSumSubarray(int k, vector<int> &arr , int N){
        int i=0,j=0;
        long sum=0,maxi=0;
        while(j<N){
            sum=sum+arr[j];
            if(j-i+1<k)
                j++;
            else if (j-i+1==k)
            {
                maxi=max(maxi,sum);
                sum=sum-arr[i];
                i++;
                j++;
            }
        }
        return maxi;
    }
