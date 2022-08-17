/*
gfg link - https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1
*/

//T.C=O(M*N)S.C=O(N*M) USED BFS
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        int n=A.size();int m=A[0].size();
        if(A[0][0]==0) return -1;
       queue<pair<pair<int,int>,int>>q;
       q.push({{0,0},0});
       A[0][0]=0;
       int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
      // vector<vector<bool>> visi(n,vector<bool>(m,0));
       while(!q.empty()){
           int i=q.front().first.first;
           int j=q.front().first.second;
           int steps=q.front().second;
           q.pop();
           if(i==X && j==Y) return steps;
           for(int k=0;k<4;k++){
               int dx=i+d[k][0];
               int dy=j+d[k][1];
               if(dx<0 ||dx>=n ||dy<0|| dy>=m ||A[dx][dy]==0) continue;
               q.push({{dx,dy},steps+1});
               A[dx][dy]=0;
           }
       }
       return -1;
    }
