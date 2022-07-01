/*
codestudio link - https://www.codingninjas.com/codestudio/problems/1062670?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
*/

//T.C=O(N+E) S.C=O(N)
bool dfs(int node,int parent,vector<int>&vis,vector<int>adj[]){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfs(it,node,vis,adj)) 
                return true;
        }
        else if(parent!=it)
            return true;
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
   vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i,-1,vis,adj)) 
                return "Yes";
        }
    }
    return "No";
}
