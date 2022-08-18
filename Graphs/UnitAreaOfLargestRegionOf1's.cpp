/*
gfg link - https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1
*/

//T.C=O(N*M) S.C=O(n*m)
   void f(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>>& d,int& area){
        if(i<0 || i>=n || j<0 || j>=m ||grid[i][j]!=1) return ;
        grid[i][j]=2;
        area++;
        for(int k=0;k<8;k++){
            f(i+d[k][0],j+d[k][1],n,m,grid,d,area);
        }
        return ;
    }
    int findMaxArea(vector<vector<int>>& grid) {
        int n=grid.size();int m=grid[0].size();
        int maxi=0;
        vector<vector<int>>d={{1,0},{-1,0},{0,-1},{0,1},{-1,1},{1,1},{-1,-1},{1,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    {
                        int area=0;
                        f(i,j,n,m,grid,d,area);
                        maxi=max(maxi,area);
                    }
            }
        }
        return maxi;
    }
