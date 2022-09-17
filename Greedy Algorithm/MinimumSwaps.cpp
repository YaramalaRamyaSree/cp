/*
gfg link - https://practice.geeksforgeeks.org/problems/minimum-swaps-1649134975/1
*/

    int minimumSwaps(int c[],int v[],int n,int k,int b,int T)
    {
           int res=0,swap=0;
           for(int i=n-1;i>=0&&k>0;i--){
               int dist=v[i]*T;
               if(dist>=b-c[i]){
                   res+=swap;
                   k--;
               }
               else
                swap++;
           }
           if(k>0)
            return -1;
          return res;
    }
