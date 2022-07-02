/*
gfg link - https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1#
*/

    //T.C=O((N+E)logn ~ NlogN, S.C=O(N)
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       int inf=INT_MAX;
       vector<int>dist(V,inf);
       dist[S]=0;
       pq.push({0,S});
       while(!pq.empty()){
           int node=pq.top().second;
           int dis=pq.top().first;
           pq.pop();
           for(auto it:adj[node]){
               if(dist[it[0]]>it[1]+dist[node]){
                   dist[it[0]]=it[1]+dist[node];
                   pq.push({dist[it[0]],it[0]});
               }
           }
       }
    return dist;
    }
