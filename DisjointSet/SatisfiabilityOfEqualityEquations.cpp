/*
leetcode link - https://leetcode.com/problems/satisfiability-of-equality-equations/
*/

class DisjointSet{
    vector<int>rank;
    vector<int>parent;
    
    public:
    
    DisjointSet(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    
    void Union (int u, int v){
        u = parent[u], v = parent[v];
        if (u == v)
            return;
        if (rank[u] > rank[v])
            parent[v] = u;
        else if (rank[u] < rank[v])
            parent[u] = v;
        else
            parent[v] = u, rank[u]++;
    }
    
    int findParent(int u){
        if (parent[u] == u)
            return u;
        return parent[u] = findParent(parent[u]);
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
       DisjointSet ds(26);
        for (auto &equation : equations)
        {
            if (equation[1] == '=' )
                ds.Union(equation[0] - 'a', equation[3] - 'a');
        }
        for (auto &equation : equations)
        {
            int u = equation[0] - 'a', v = equation[3] - 'a';
            if (equation[1] == '!' and ds.findParent(u) == ds.findParent(v))
                return false;
        }
        return true; 
    }
};
