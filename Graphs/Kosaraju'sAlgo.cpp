/*
codestudio lnk - https://www.codingninjas.com/codestudio/problems/985311?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
*/

//T.C=O(n+e) S.c=o(n+e)
#include <bits/stdc++.h>
void dfs(int node, vector<int>adj[],stack<int>&st,vector<int>&vis){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it])
            dfs(it,adj,st,vis);
    }
    st.push(node);
}
void revdfs(int node,vector<int>adj[],vector<int>&v,vector<int>&vis){
    vis[node]=1;
    v.push_back(node);
    for(auto it:adj[node]){
        if(!vis[it])
            revdfs(it,adj,v,vis);
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<int>adj[n];
    vector<int>adjrev[n];
    stack<int>st;
    vector<int>vis(n,0);
    vector<vector<int>>ans;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
  //VERY VERY IMPORTANT  CHECKING FOR ALL COMPONENTS IN GRAPH 
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,adj,st,vis);
        }
    }
 
    for(int it=0;it<n;it++){
        vis[it]=0;
        for(auto i :adj[it]){
            adjrev[i].push_back(it);
        }
    }

    while(!st.empty()){
        int node =st.top();
        st.pop();
        if(!vis[node]){
            vector<int>v;
            revdfs(node,adjrev,v,vis);
            ans.push_back(v);
        }     
    }
    return ans;
}
