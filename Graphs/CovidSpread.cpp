/*
gfg link - https://practice.geeksforgeeks.org/problems/269f61832b146dd5e6d89b4ca18cbd2a2654ebbe/1
*/

//T.C=O(N*M) S.C=O(N*M) USED BFS
    int helpaterp(vector<vector<int>>&hospital)
    {
        int n=hospital.size();int m=hospital[0].size();
        int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int>>q;
        int tot=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(hospital[i][j]==2){
                    q.push({i,j});
                }
                if(hospital[i][j]!=0) tot++;
            }
        }
        int level=0;int cnt=0;
        while(!q.empty()){
            int size=q.size();
            cnt+=size;
            while(size--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int dx=i+d[k][0];
                    int dy=j+d[k][1];
                    if(dx<0 || dx>=n ||dy<0 || dy>=m ||hospital[dx][dy]!=1) continue;
                    hospital[dx][dy]=2;
                    q.push({dx,dy});
                }
            }
            if(!q.empty())
            level++;
        }
        return (tot==cnt?level:-1);
    }
