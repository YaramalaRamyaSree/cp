/*
gfg link - https://practice.geeksforgeeks.org/problems/partition-array-to-k-subsets/0
*/

   bool helper(int currsum,int sum,int n,int k,vector<bool>&vis,int a[]){
        if(k==1)
            return 1;
        if(currsum>sum)
            return 0;
        if(currsum==sum)
            return helper(0,sum,n,k-1,vis,a);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=1;
                if(helper(currsum+a[i],sum,n,k,vis,a)) 
                    return 1;
                vis[i]=0;
            }
            
        }
        return 0;
    }
    
    bool isKPartitionPossible(int a[], int n, int k)
    {
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=a[i];
        if(k>n||sum%k!=0)
            return 0;
        sum/=k;
        vector<bool>vis(n,0);
        return helper(0,sum,n,k,vis,a);
            
    }
