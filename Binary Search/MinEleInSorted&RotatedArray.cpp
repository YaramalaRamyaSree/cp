/*
gfg link - https://practice.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1
*/
    //T.C=O(logN) S.C=O(1)
    //This question can also be asked in different way how many rotations happened its same index of minele (if clockwise rotation) if anticlock its n-index of min ele
    int findMin(int arr[], int n){
        int l=0,h=n-1;
        while(l<=h){
            if( l==h || arr[l]<arr[h]) return arr[l];
            int mid=l+(h-l)/2;
            if(mid!=0 && arr[mid-1]>arr[mid]){
                return arr[mid];}
            if(mid!=n-1 && arr[mid+1]<arr[mid]){
                return arr[mid+1];}
            if(arr[l]>arr[mid])
                h=mid-1;
            else
                l=mid+1;
        }
        return -1;
    }
