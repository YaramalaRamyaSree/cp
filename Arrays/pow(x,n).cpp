/*
leetcode link - https://leetcode.com/problems/powx-n/
*/

// T.C=O(log(N)) S.C=O(1)
//exponent n if it is -ve there is an edge case, when we convert n as positive i.e = overflow so change datatype of exponent.

double myPow(double x, int n) {
        double ans=1.0;
        long long exp=n;
        if(n<0) exp= -1*exp;
        while(exp>0){
            if(exp%2==1){
                ans=ans*x;
                exp=exp-1;
            }
            else{
                x=x*x;
                exp=exp/2;
            }
        }
        if(n<0) ans=(double)1.0/(ans);
        return ans;
    }
