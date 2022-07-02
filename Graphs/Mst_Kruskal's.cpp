/*
codestudio link - https://www.codingninjas.com/codestudio/problems/1082553?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
*/

//T.C=O(ElogE),S.c=O(N)
#include <algorithm>
bool comparator(vector<int>a,vector<int>b)
{
    return a[2]<b[2];
}
int findpar(int node, vector<int>&parent){
    if(node==parent[node]) return node;
    return parent[node]=findpar(parent[node],parent);
}
void unionn(int node1,int node2,vector<int>&parent,vector<int>&rank){
    node1=parent[node1];
    node2=parent[node2];
    if(rank[node1]<rank[node2]){
        parent[node1]=node2;
    }else if(rank[node1]>rank[node2]){
        parent[node2]=node1;
    }else
    {
        parent[node2]=node1;
        rank[node2]++;
    }
}
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
    sort(graph.begin(),graph.end(),comparator);
	vector<int>parent(n+1);
    for(int i=0;i<n;i++){
           parent[i]=i;
    }
    vector<int>rank(n+1,0);
    int cost=0;
    for(int i=0;i<m;i++){
        int u=graph[i][0];
        int v=graph[i][1];
        int wt=graph[i][2];
        if(findpar(u,parent)!=findpar(v,parent)){
            cost+=wt;
            unionn(u,v,parent,rank);
        }
    }
    return cost;
}
