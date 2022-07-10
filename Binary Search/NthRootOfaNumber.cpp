/*
code studio - https://takeuforward.org/data-structure/nth-root-of-a-number-using-binary-search/
*/

//T.C=O(LOG (m*10^d) base 2)*N  m is number n is root d decimal point where we need answer 

//here search space is not just m its m*10^d because we nneded answer till d decimals 

long double multiply(long double mid,int n){
    long double mul=1.0;
    while(n--){
        mul*=mid;
    }
    return mul; 
}
long double findNthRootOfM(int n, long long m) {
    long double low=1.0,high=(long double)m,abs=1e-9;
    while((high-low)>abs){
        long double mid=(high-low)/2.0+low;
        if(multiply(mid,n)>(long double)m){
            high=mid;
        }
        else{
            low=mid;
        }
    }
    return low; 
}

