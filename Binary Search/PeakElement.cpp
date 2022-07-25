/*
gfg link - https://practice.geeksforgeeks.org/problems/peak-element/1
*/

    //T.C=O(logN),S,C=O(1)
    int peakElement(int arr[], int n)
    {
      int l=0,h=n-1;
      int mid;
      // we are sure atleast one peak element exist;
      while(l<=h){
            mid=l+(h-l)/2;
            if((mid==0 || arr[mid-1]<=arr[mid]) && (mid==n-1 || arr[mid+1]<=arr[mid])){
                return mid; } //condition for middle element to be peak 
            if(mid>0 && arr[mid-1]>arr[mid]){
              // we are sure that peak exists in left side to mid if arr[mid-1]>arr[mid]
                h=mid-1;}
            else
            {//we are sure it exits in right side to mid
              l=mid+1;} 
      }
      return mid;
    }
