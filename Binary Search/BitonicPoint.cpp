/*
gfg link - https://practice.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array3001/1
*/

  //T.C=O(logN) S.C=O(1)
	int findMaximum(int arr[], int n) {
	   int l=0,h=n-1;
	   while(l<=h){
	       int mid=l+(h-l)/2;
	       if((mid==0||arr[mid-1]<arr[mid])&&(mid==n-1 ||arr[mid]>arr[mid+1]))
	        return arr[mid];
	       else if(arr[mid-1]<arr[mid])
	        l=mid+1;
	       else
	        h=mid-1;
	   }
	   return -1;
	}
