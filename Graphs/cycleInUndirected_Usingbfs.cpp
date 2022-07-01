/*
codestudio link - https://www.codingninjas.com/codestudio/problems/1062670?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
*/

//T.C=O(N+E) S.C=O(N)
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
   vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<pair<int,int>>q;
    vector<int>vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            q.push(make_pair(i,-1));
            vis[i]=1;
            while(!q.empty()){
                int node=q.front().first;
                int parent=q.front().second;
                q.pop();
                for(auto it:adj[node]){
                    if(!vis[it]){
                    q.push({it,node});
                        vis[it]=1;
                    }
                    else if(parent!=it)
                        return "Yes";
                } 
            }
        }
    }
    return "No";
}
