/*
leetcode link - https://leetcode.com/problems/mirror-reflection/
*/


    //T.C=log(max(p,q)) S.C=O(1)
    //extension*p=reflection*q;
    //extension=no of extension+1,reflection = no of refelctions+1;
    //take p=3,q=2  p=2,q=2, p=3,q=1 and observe we conclude
    //if ext and ref are odd receptor is 1
    //if ext is even and ref is odd receptor is 0
    //if ext is odd and ref is even receptor is 2
    int mirrorReflection(int p, int q) {
        int ext=q,ref=p;
        int g=__gcd(p,q);
        ref/=g;
        ext/=g;
        return 1-ref%2+ext%2;
      
        /*while(!(ext&1) && !(ref&1)){
            ext/=2;ref/=2;
        }
        if(ext&1 && ref&1) return 1;
        if(!(ext&1) && ref&1) return 0;
        if(ext&1 && !(ref&1)) return 2;
        */
        
        /*
        while(ext%2==0 && ref%2==0)
        {
        ext>>=1;
        ref>>=1;
        }
        return 1-ref%2+ext%2;
        */
    }
