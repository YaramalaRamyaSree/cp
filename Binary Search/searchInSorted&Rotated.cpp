/*
gfg link - https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array0959/1
*/

//T.C=O(logN),S.C=O(1)
// vec : given vector of elements
// K : given value whose index we need to find 
int Search(vector<int> arr, int K) {
    int l=0,h=arr.size()-1;
    int ans =-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(arr[mid]==K){
            return mid;
        }
        if(arr[l]<arr[mid]){ // left side sorted 
            if(arr[l]<=K && arr[mid]>K){//check if left is useful for us
                h=mid-1;
            }
            else
                l=mid+1;
        }
        else{//right side sorted
            if(arr[mid]<K && arr[h]>=K){//check if right sorted is useful 
                l=mid+1;
            }
            else
                h=mid-1;
        }
    }
    return ans;
}
