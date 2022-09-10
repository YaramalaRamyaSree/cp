/*
gfg link - https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately-1587115620/1
*/

//T.C=O(N) S.C=O(N) TWO POINTER APPROACH
    void rearrange(long long *arr, int n) 
    { 
        vector<int>v;
    	int j=n-1;
    	int i=0;
    	    
        while(i<=n/2){
    	    v.push_back(arr[j]);
    	    v.push_back(arr[i]);
    	    j--;
    	    ++i;
    	}
    	for(int k=0;k<n;k++) arr[k]=v[k];
   }

//OPTIMAL 
//IDEA: storing two elements at one location
//T.C=O(N) S.C=O(1)
    void rearrange(long long *arr, int n) 
    { 
    	int maxi=n-1;//maxi
    	int mini=0;//mini
    	int me=arr[maxi]+1;//maxelement+1
    	int i=0;
        while(i<n){
    	   if(i%2==0)
    	    arr[i]=arr[i]+(arr[maxi--]%me)*me;
    	   else arr[i]=arr[i]+(arr[mini++]%me)*me;
    	   i++;
    	}
    	for(int k=0;k<n;k++) arr[k]=arr[k]/me;
   }
