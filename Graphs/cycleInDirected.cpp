/*
leetcode link - https://leetcode.com/problems/course-schedule/ 
*/

    //This question hasn't asked directly finding cycle in directed graph but crux's of whole question lies here.
    //T.C=O(N+E)S.C=O(N)
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      //forming adj list
        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
        }
      
      //creating vis and dfs vis 
        vector<int>vis(numCourses,0);
        vector<int>dfs_vis(numCourses,0);
      //find is cycle present in all components of graph
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(iscycle(i,dfs_vis,vis,adj))
                    return false;
            }
        }
        return true;
    }
    
    bool iscycle(int node,vector<int>&dfs_vis,vector<int>&vis,vector<int>adj[]){
        vis[node]=1;
        dfs_vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(iscycle(it,dfs_vis,vis,adj)) return true;
            }
          //if current node present in both vis and dfs_vis that means cycle exists.
            else if(dfs_vis[it])
                return true;
        }
        dfs_vis[node]=0;
        return false;
    }
