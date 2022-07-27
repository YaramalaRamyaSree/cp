/*
gfg link -  https://practice.geeksforgeeks.org/problems/matrix-exponentiation2711/1
*/

   //T.C=O(logN) S.C=O(K) K IS CONSTANT .
   typedef vector<vector<long long int>> matrix;
    int m=1e9+7;
    matrix matMul(matrix a,matrix b){
        matrix ans(2,vector<long long>(b[0].size(),0));
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b[0].size();j++){
                for(int k=0;k<b.size();k++){
                    ans[i][j]=(ans[i][j]+a[i][k]*b[k][j])%m;
                }
            }
        }
        return ans;
    }
    
    matrix matExp(matrix base, long long n){
        if(n==1) return base;
        long long half=n/2;
        matrix ans=matExp(base,half);
        ans=matMul(ans,ans);
        if(n&1)
            ans=matMul(ans,base);
        return ans;
    }

    int FindNthTerm(long long int n) {
        if(n==0||n==1) return 1;
        matrix base(2,vector<long long>(2,0));
        base[0][0]=base[0][1]=base[1][0]=1;
        base[1][1]=0;
        matrix initial(2,vector<long long>(1,0));
        initial[0][0]=initial[1][0]=1;
        matrix powerbase=matExp(base,n-1);
        matrix ans=matMul(powerbase,initial);
        return ans[0][0];
    }
