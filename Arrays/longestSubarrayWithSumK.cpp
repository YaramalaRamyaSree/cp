/*   
gfg link - https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
*/
//T.C=O(N) S.C=O(N)
int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        int maxi=0;
        int sum=0;
        unordered_map<int,int>m;
        for(int i=0;i<N;i++){
            sum+=A[i];
            if(sum==k) 
                maxi=i+1;
            if(m.find(sum-k)!=m.end()){
                maxi=max(maxi,i-m[sum-k]);
            }
            if(m.find(sum)==m.end())
                m[sum]=i;
        }
        return maxi;
    } 
