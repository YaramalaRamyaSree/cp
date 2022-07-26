/*
gfg link - https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
*/
    //T.C=O(NlogN) ,S.C=O(1)
    bool isPossibleToAllocate(int arr[],int n ,int m,int mid){
        int students=1,currpages=0;
        for(int i=0;i<n;i++){
            if(currpages+arr[i]>mid){
                students++;
                if(students>m) return false;
                currpages=arr[i];
            }
            else
                currpages+=arr[i];
        }
        return true;
    }
    int findPages(int arr[], int N, int M) 
    {
        if(M>N) return -1;
        //as here  already sorted max ele is cake walk 
        int l=arr[N-1],h=accumulate(arr,arr+N,0);
        int res=INT_MAX;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(isPossibleToAllocate(arr,N,M,mid)){
                res=mid;
                h=mid-1;
            }
            else
                l=mid+1;
        }
        return res;
    }
