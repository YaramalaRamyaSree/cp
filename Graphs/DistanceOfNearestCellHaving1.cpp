/*
gfg link - https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
*/

//T.C=O(M*N) S.C=(M*N) USED BFS
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
	    vector<vector<int>>ans(grid.size(),vector<int>(grid[0].size(),0));
	    vector<vector<bool>>visi(grid.size(),vector<bool>(grid[0].size(),false));
	    queue<pair<int,int>>q;
	    for(int i=0;i<grid.size();i++){
	        for(int j=0;j<grid[0].size();j++){
	            if(grid[i][j]==1) {
	                q.push({i,j});
	                visi[i][j]=true;
	            }
	        }
	    }
	    
	    while(!q.empty()){
	        int i=q.front().first;
	        int j=q.front().second;
	        q.pop();
	        for(int k=0;k<4;k++){
	            int dx=i+d[k][0];
	            int dy=j+d[k][1];
	            if(dx<0 || dx>=grid.size() || dy<0 || dy>=grid[0].size()|| visi[dx][dy]) 
	                continue;
    	           ans[dx][dy]=ans[i][j]+1;
    	           q.push({dx,dy});
    	           visi[dx][dy]=true;}
	    }
	    return ans;
	}
