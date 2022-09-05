/*
gfg link - https://practice.geeksforgeeks.org/problems/the-celebrity-problem/0
*/

//T.C=O(N) 
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>s;
        for(int i=0;i<n;i++){
            s.push(i);
        }
        while(s.size()>=2){
            int i=s.top();
            s.pop();
            int j=s.top();
            s.pop();
            if(M[i][j]==1)
            {
                s.push(j);
            }
            else {
                s.push(i);
            }
        }
        
        int potential=s.top();
        s.pop();
        for(int i=0;i<n;i++){
            if(i!=potential)
            {
                if(M[i][potential]==0 ||M[potential][i]==1 )
                    return -1;
            }
        }
        return potential;
    }
