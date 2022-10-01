/*
gfg link - https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1
*/

//T.C=O(m*n)
    void helper(int i,int j,vector<vector<int>>&grid,int m,int n,string&s){
        if(i>=m || i<0 || j<0 || j>=n || grid[i][j]!=1)
            return;
        grid[i][j]=2;
        s+="u";
        helper(i-1,j,grid,m,n,s);
        s+="l";
        helper(i,j-1,grid,m,n,s);
        s+="r";
        helper(i,j+1,grid,m,n,s);
        s+="d";
        helper(i+1,j,grid,m,n,s);
    }
  
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        set<string>st;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    string s="";
                    helper(i,j,grid,m,n,s);
                    st.insert(s);
                }
            }
        }
    return st.size();
    }
