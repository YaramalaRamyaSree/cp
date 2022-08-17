/*
gfg link - https://practice.geeksforgeeks.org/problems/find-whether-path-exist5238/1
*/

//T.C=O(N*M) S.C=O(N*M) USED DFS
    bool f(int i,int j,vector<vector<int>>& grid,int d[4][2],int n,int m){
        if(i<0 || i>=n ||j<0 || j>=m|| grid[i][j]==0) return false;
        if(grid[i][j]==2) return true;
        grid[i][j]=0;//like marking visited ( idea of using wall only as visited)
        bool ans=false;
        for(int k=0;k<4;k++){
            ans=ans||f(i+d[k][0],j+d[k][1],grid,d,n,m);
        }
        return ans;
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n=grid.size();int m=grid[0].size();
        int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    return  f(i,j,grid,d,n,m);
            }
        }
        return 1;
    }
