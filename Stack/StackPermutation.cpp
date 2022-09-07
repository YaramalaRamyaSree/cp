/*    
gfg link - https://practice.geeksforgeeks.org/problems/stack-permutations/1
*/

//t.c=o(n) s.c=o(n)
int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        stack<int>s;
        int j=0;
        for(int i=0;i<N;i++)
        {   
            s.push(A[i]);
            while (!s.empty()&&B[j]==s.top()){
                s.pop();j++;}
        }
       
        if (s.size()==0)return 1;
        else return 0;
    }
