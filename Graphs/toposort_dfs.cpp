/*
gfg link - https://practice.geeksforgeeks.org/problems/topological-sort/1#
*/

	//T.C=O(N+E),S.C=O(N)
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>vis(V,0);
	    vector<int>topo;
	    stack<int>st;
	    for(int i=0;i<V;i++){
	        if(!vis[i])
	            toposort(i,adj,vis,st);
	    }
	    while(!st.empty()){
	        topo.push_back(st.top());
	        st.pop();
	    }
	    return topo;
	}
	
	void toposort(int node,vector<int>adj[],vector<int>&vis,stack<int>&st){
	    vis[node]=1;
	    for(auto it: adj[node]){
	        if(!vis[it])
	            toposort(it,adj,vis,st);
	    }
	    st.push(node);
	}
