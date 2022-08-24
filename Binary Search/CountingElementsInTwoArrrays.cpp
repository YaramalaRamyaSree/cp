/*
gfg link - https://practice.geeksforgeeks.org/problems/counting-elements-in-two-arrays/1
*/

//T.c=nlogn+mlogn =(m+n) logn ,s.c=o(1)
  int helper(int x, int arr[],int n){
      int i=0,j=n-1;
      int index=-1;
      while(i<=j){
          int mid=i+(j-i)/2;
          if(arr[mid]>x){
             index=mid;
            j=mid-1;}
            else    i=mid+1;
      }
      if(index==-1) return n;
      else return index;
  }
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], 
                                 int m, int n)
    {
    sort(arr2,arr2+n);
    vector<int>ans;
    for(int i=0;i<m;i++){
        ans.push_back(helper(arr1[i],arr2,n));
    }
    return ans;
    }
