/*
gfg link - https://practice.geeksforgeeks.org/problems/knight-walk4521/1
*/

  //t.c=o(n^2) s.c=o(n^2)
 //using bfs algo 
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    short int d[8][2] = {{-1, 2}, {1, 2}, {-1, -2}, {1, -2}, {-2, -1}, {2, -1}, {-2, 1}, {2, 1}};
	    vector<vector<bool>>vis(N+1,vector<bool>(N+1,false));
	    queue<pair<pair<int,int>,int>>q;
	    int steps=0;
	    q.push({{KnightPos[0],KnightPos[1]},steps});
	    while(!q.empty())
	    {
	        int i=q.front().first.first;
	        int j=q.front().first.second;
	        steps=q.front().second;
	        q.pop();
	        if(i==TargetPos[0]&&j==TargetPos[1])
	            return steps;
	        for(int k=0;k<8;k++)
	        {
	            int dx=i+d[k][0];
	            int dy=j+d[k][1];
	            if(dx<1 || dx>N || dy<1 || dy>N || vis[dx][dy]) 
	                continue;
	            q.push({{dx,dy},steps+1});
	            vis[dx][dy]=true;
	        }
	    }
	    return -1;
	}
