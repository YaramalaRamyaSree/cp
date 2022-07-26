/*
gfg link - https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
*/
  
    //T.C=O(NlogM) N-no of boards to paint,M-sum of all board units,S.C=O(1) 
    bool isPossibleToPaint(int arr[],int n,int k,long long mid){
        int painters=1;long long currtime=0;
        for(int i=0;i<n;i++){
            
            if(currtime+arr[i]>mid){
                painters++;
                if(painters>k) return false;
                currtime=arr[i];
            }
            else
                currtime+=arr[i];
        }
        return true;
    }
    long long minTime(int arr[], int n, int k)
    {
      //here array is not sorted but a painter can paint only contagious boards 
      //l is max ele and h is sum 
      //we should not change array(sort) bcz we can only paint contagious boards 
       long long l=*max_element(arr,arr+n),h=accumulate(arr,arr+n,0L);
       long long res=LLONG_MAX;
       while(l<=h){
           long long mid= l+(h-l)/2;
           if(isPossibleToPaint(arr,n,k,mid)){
               res=mid;
               h=mid-1;
           }
           else
                l=mid+1;
       }
       return res;
    }
