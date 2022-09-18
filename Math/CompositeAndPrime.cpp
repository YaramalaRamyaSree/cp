/*
gfg link - https://practice.geeksforgeeks.org/problems/composite-and-prime0359/1
*/

//T.C=O(NlogN) S.C=O(N)
		int Count(int L, int R){
		   bool prime[R+1];
		   memset(prime,true,sizeof(prime));
		   for(int i=2;i*i<=R;i++){
		       if(prime[i]){
		           for(int j=i*i;j<=R;j+=i){
		               prime[j]=false;
		           }
		       }
		   }
		   int p=0,c=0;
		   if(L==1)L=2;
		   for(int i=L;i<=R;i++){
		       if(prime[i])
		        p++;
		        else
		        c++;
		        
		   }
		   return c-p;
		}
