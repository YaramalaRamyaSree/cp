/*
gfg link - https://practice.geeksforgeeks.org/problems/topological-sort/1#
*/

	//T.C=O(N+E),S.C=O(N)
	vector<int> topoSort(int v, vector<int> adj[]){
	       vector<int>degree(v,0);
            for(int i=0;i<v;i++){
                for(auto it:adj[i]){
                    degree[it]++;
                }
            }
            queue<int>q;
            for(int i=0;i<v;i++){
                if(degree[i]==0)
                    q.push(i);
            }
            vector<int>topo;
            while(!q.empty()){
                int node =q.front();
                q.pop();
                topo.push_back(node);
                for(auto it:adj[node]){
                    degree[it]--;
                    if(degree[it]==0) q.push(it);
                }
            }
            return topo;
	}
