/*
gfg link - https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1#
*/

//T.C=O(N+E),S.C=O(N)
    void dfs(int node , vector<int>&vis, vector<int>&ans, vector<int> adj[],int V){
        vis[node]=1;
        ans.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it])
            dfs(it,vis,ans,adj,V);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        vector<int>vis(V,0);
        //We check for all components 
        for(int i=0;i<V;i++){
            if(!vis[i])
                dfs(i,vis,ans,adj,V);
        }
        return ans;
    }
