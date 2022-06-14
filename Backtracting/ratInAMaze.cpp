/*
gfg link - https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
*/

    //T.C: O(4^(m*n)), because on every cell we need to try 4 different directions.

    //S.C:  O(m*n) ,Maximum Depth of the recursion tree(auxiliary space).
    
    vector<string> findPath(vector<vector<int>> &mat, int n) {
        int di[4]={+1,0,0,-1},dj[4]={0,-1,+1,0};
        vector<string>ans;
        vector<vector<int>>visited(n,vector<int>(4,0));
        if(mat[0][0])
        find(0,0,mat,n,"",di,dj,visited,ans);
        if(ans.size()==0) return {"-1"};
        return ans;
    }
    
    void find(int row,int col,vector<vector<int>> mat,int n,
    string s,int di[],int dj[],vector<vector<int>> &visited,vector<string>&ans){
        if(row==n-1&&col==n-1) ans.push_back(s);
        string d="DLRU";
        for(int i=0;i<4;i++){
            int nextrow=row+di[i];
            int nextcol=col+dj[i];
            if(nextrow>=0 && nextrow<n && nextcol<n && nextcol>=0 && mat[nextrow][nextcol]==1 && visited[nextrow][nextcol]==0){
                visited[row][col]=1;
                find(nextrow,nextcol,mat,n,s+d[i],di,dj,visited,ans);
                visited[row][col]=0;
            }
        }
    }
