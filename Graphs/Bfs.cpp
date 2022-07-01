/*
gfg link - https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
*/
  
//T.C=O(N+E),S.C=O(N)
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int>q;
        q.push(0);
        vector<int>bfs,vis(V,0);
        vis[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it:adj[node])
            {   
                if(!vis[it])
                {
                q.push(it);
                vis[it]=1;}
                }
        }
        return bfs;
    }
