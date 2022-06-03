/*
gfg link - https://practice.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1#
*/

//T.C=O(N(,S.C=O(N) ->IDEA OF STORING REMAINDERS IN HASH MAP AND CHECKING IN ONE PASS (ARR CAN HAVE -VE VALUES SO TAKE CARE OF REMAINDER)
int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    unordered_map<int,int>m;
	    int sum=0;
	    int maxlength=0;
	    
	    m.insert({0,-1});
	    
	    for(int i=0;i<n;i++){
	        
	        sum+=arr[i];
	        
	        int rem= sum%k;
	        
	        if(rem<0) rem=rem+k;
	        
	        if(m.find(rem)!=m.end() )
	        
	            maxlength=max(maxlength,i-m[rem]);
	        else
	        
	            m[rem]=i;
	        
	    }
	    return maxlength;
	}
