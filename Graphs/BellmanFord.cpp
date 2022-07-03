/*
gfg link - https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0/?fbclid=IwAR2_lL0T84DnciLyzMTQuVTMBOi82nTWNLuXjUgahnrtBgkphKiYk6xcyJU
*/

    //T.C=O(E*V)S.C=O(N)
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        vector<int>dist(V,100000000);
        dist[S]=0;
        for(int i=1;i<=V-1;i++){
            for(auto it:adj){
                if(dist[it[0]]+it[2]<dist[it[1]]){
                    dist[it[1]]=dist[it[0]]+it[2];
                }
            }
        }
        return dist;
    }
