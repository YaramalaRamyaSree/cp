/*
gfg link - https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
*/

// Finding cost is shown in code 
//If we need path create a parent vector and modify while consideresing that node in mst 

//T.C=O(NlogN),S.C=O(N)

    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int>key(V,INT_MAX);
        vector<bool>mst(V,false);
        key[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        int cost=0;
        while(!pq.empty()){
            if(mst[pq.top().second]){
                pq.pop();
                continue;
            }
            int node =pq.top().second;
            cost += pq.top().first;
            pq.pop();
            mst[node]=true;
            for(auto it:adj[node]){
                if(mst[it[0]]==false && key[it[0]]>it[1]){
                    key[it[0]]=it[1];
                    pq.push({key[it[0]],it[0]});
                }
            }
        }
        
    return cost;
    }
