/*
gfg link - https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1
*/

   int orangesRotting(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       queue<pair<int,int>>q;
       int tot=0;
       //we keep in queue all rotten (2) and which we made rotten(1) this count should be equal to tot else we return -1 
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(grid[i][j]==2)//rotten{
                   q.push({i,j});
               if(grid[i][j]!=0) tot++;
            }
        }
        int cnt=0,level=0;
        int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int size=q.size();
            cnt+=size;
            while(size--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int dx=i+d[k][0];
                    int dy=j+d[k][1];
                    if(dx<0 || dx>=n ||dy<0 ||dy>=m || grid[dx][dy]!=1) continue;
                    grid[dx][dy]=2;//used grid only as visited also 
                    q.push({dx,dy});
                }
            }
            if(!q.empty()){
                level++;
            }
        }
        return tot==cnt?level:-1; 
       }
