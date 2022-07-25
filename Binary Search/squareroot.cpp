/*
gfg link - https://practice.geeksforgeeks.org/problems/square-root/1
*/
  
    //T.C=O(logN) S.C=O(1)
    long long int floorSqrt(long long int x) 
    {
        if(x==1) return 1;
        long long int l=1,h=x/2;
        long long int ans;
        while(l<=h){
            long long int mid=l+(h-l)/2;
            long long int Sqr=mid*mid;
            if(Sqr>x)
                h=mid-1;
            else if(Sqr<x){
                ans=mid;
                l=mid+1;
            }
            else
                return mid;
        }
    return ans;
    }
