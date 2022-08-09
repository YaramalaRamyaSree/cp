/*
gfg link - https://practice.geeksforgeeks.org/problems/nine-divisors3751/1
*/

class Solution{  
    private:
   void generatePrime(vector<int>&primes){
        for(int i=2;i<primes.size();i++){
        primes[i]=i;
        }
        for(int i=2;i*i<primes.size();i++){
            if(primes[i]==i)
            for(int j=i*i;j<primes.size();j+=i){
                if(primes[j]==j)
                  primes[j]=i;
            }
        }
    }
public:
    long long int nineDivisors(long long int N){
        vector<int>primes(sqrt(N)+1,1);
      //seive ->smallest prime factor
        generatePrime(primes);
      //A number can have 9 divisors if it is in form n=(p^2*q^2) || n=(r^8) where p,q,r are prime numbers 
      //n=(pq)^2 => pq=root(n) => p=root(n)/q
        int c=0;
        for(int i=2;i<=sqrt(N);i++){
            int a=primes[i];
            int b=primes[i/a];
            if((a!=b && primes[b]==b && b!=1 && (a*b)==i) ||(primes[i]==i && pow(i,8)<=N))
            c++;
        }
        return c;
    }
};
