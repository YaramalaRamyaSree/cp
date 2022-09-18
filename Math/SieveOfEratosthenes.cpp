/*
gfg link- https://practice.geeksforgeeks.org/problems/sieve-of-eratosthenes5242/1
*/

    vector<int> sieveOfEratosthenes(int N)
    {
        bool prime[N+1];
        memset(prime,true,sizeof(prime));
        for(int i=2;i*i<=N;i++){
            if(prime[i]){
                for(int j=i*i;j<=N;j+=i)
                    prime[j]=false;
            }
        }
        vector<int>ans;
        for(int i=2;i<=N;i++){
           if(prime[i]) ans.push_back(i);
        }
        return ans;
    }
