/*
leetcode link - https://leetcode.com/problems/next-permutation/
*/

    void nextPermutation(vector<int>& A) {
        
        if(A.size()==1) return ;
        
        int i = A.size()-2,j=A.size()-1;
        
        while(i>=0 && A[i]>=A[i+1]) i--;
        
        if(i>=0){
            while(A[i]>=A[j]) j--;
            swap(A[i],A[j]);
        }
        
        j=A.size()-1;i=i+1;
        
        while(i<j){
            swap(A[i++],A[j--]);
        }
        
    }
