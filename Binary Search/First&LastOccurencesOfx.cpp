/*
gfg link - https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/0
*/

//T.C=O(logN) S.C=o(1)
vector<int> find(int arr[], int n , int x )
{
    if(!binary_search(arr,arr+n,x)) return {-1,-1};
    int first=-1,last=-1;
    first=lower_bound(arr,arr+n,x)-arr;
    last=upper_bound(arr,arr+n,x)-arr;
    return {first,last-1};
}
