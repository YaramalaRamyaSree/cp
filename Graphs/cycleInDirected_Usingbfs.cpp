/*
codestudio link - https://www.codingninjas.com/codestudio/problems/1062626?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
*/

//T.C=O(N+E) S.C=O(N)
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
   vector<int>adj[n+1];
   for(int i=0;i<edges.size();i++){
      int u=edges[i].first;
      int v=edges[i].second;
      adj[u].push_back(v);
   }
   vector<int>indegree(n+1,0);
   for(int i=1;i<=n;i++){
       for(auto it:adj[i]){
           indegree[it]++;
       }
   }
   queue<int>q;
   for(int i=1;i<=n;i++){
       if(indegree[i]==0)
           q.push(i);
   }
   int count=0;
   while(!q.empty()){
       int node=q.front();
       q.pop();
       count++;
       for(auto it:adj[node]){
           indegree[it]--;
           if(indegree[it]==0)
               q.push(it);
       }
   }
   if(count==n)
       return 0;
   return 1;
    
}
