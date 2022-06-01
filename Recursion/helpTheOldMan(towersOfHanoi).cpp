/*
gfg link - https://practice.geeksforgeeks.org/problems/help-the-old-man3848/1
*/
    
    //T.C=O(2^N)
    int step=0;
    void Toh(int N,int a,int b, int c,int n,vector<int>&v){
        if(N>0){
            Toh(N-1,a,c,b,n,v);
            step++;
            if(step==n){
                v.push_back(a);
                v.push_back(c);
            }
            Toh(N-1,b,a,c,n,v);
        }
    }
    vector<int> shiftPile(int N, int n){
        vector<int>v;
        Toh(N,1,2,3,n,v);
        return v;
    }
