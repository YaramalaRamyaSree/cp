/*
gfg link - https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
*/

//T.C=O(N) S.C=O(1) - sliding window aproach .
// we could also do it using hashing and 2 loops but both give TLE bcz we use either extraspace or we do in n2 TC
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        if(s==0) return {-1};
        long long sum=0;
        int i=0,j=0;
        while(i<n){
            if(sum==s) return {i+1,j};
            while(sum<s) sum+=arr[j++];
            while(sum>s) sum-=arr[i++];
        }
        return {-1};
    }
