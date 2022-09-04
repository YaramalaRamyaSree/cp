/*
gfg link - https://practice.geeksforgeeks.org/problems/subset-sums-between-the-given-range/0
*/

//T.C=O(2^(n)) S.c=o(n) 
    void helper(int i,int n,int l,int r,vector<int>&arr,long long int &count,long long int sum){
        
        if(i==n){
            if(sum>=l && r>=sum)
                count++;
            return;
        }
        helper(i+1,n,l,r,arr,count,sum);
        helper(i+1,n,l,r,arr,count,sum+arr[i]);
        return;
    }
    
    long long int countSubsets(vector<int>&arr, int n, int l, int r){
        long long int count=0,sum=0;
        helper(0,n,l,r,arr,count,sum);
        return count;
    }

//Efficient  T.C=O( 2^N/2 * log(2^n/2) ) s.c=o(2^n/2) in gfg blog 
