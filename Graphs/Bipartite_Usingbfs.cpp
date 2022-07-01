/*
leetcode link - https://leetcode.com/problems/is-graph-bipartite/
*/

    //  T.C=O(N+E) S.C=O(N)
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        queue<int>q;
        for(int i=0;i<graph.size();i++){
        
            if(color[i]==-1){
                color[i]=1;
                q.push(i);
                
                while(!q.empty()){
                    int node =q.front();
                    q.pop();
                   
                    for(auto it:graph[node]){
                        
                        if(color[it]==-1){
                            color[it]=1-color[node];
                            q.push(it);
                        }
                        
                        else if(color[it]==color[node])
                            return false;
                    }
                }
            }
            
        }
        return true;
    }
