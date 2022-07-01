/*
leetcode link - https://leetcode.com/problems/is-graph-bipartite/
*/

//T.C=O(N+E) S.C=O(N)
//Here color vector itslef works as visited in actual dfs 
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        queue<int>q;
        for(int i=0;i<graph.size();i++){
        
            if(color[i]==-1){
                color[i]=1;
                if(canColor(i,color,graph)==false)
                    return false;
             }
        }
        return true;
    }
    
    bool canColor(int node,vector<int>&color,vector<vector<int>>&graph){
        for(auto it:graph[node]){
            if(color[it]==-1){
                color[it]=1-color[node];
                if(!canColor(it,color,graph))
                    return false;
            }
            else if(color[it]==color[node])
                return false;
        }
        return true;
    }
