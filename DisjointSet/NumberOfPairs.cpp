/*
gfg link - https://practice.geeksforgeeks.org/problems/number-of-pairs-1645358985/1
*/
//T.C=O(N) S.C=O(N)
class DisjointSet{
        vector<int>rank;
        vector<int>parent;
        public:
        DisjointSet(int n){
            rank.resize(n,0);
            for(int i=0;i<n;i++)
                parent.push_back(i);
        }
        void Union(int x,int y){
            x=find(x);
            y=find(y);
            if(x==y) return ;
            if(rank[x]>rank[y])
                parent[y]=x;
            else if(rank[x]<rank[y])
                parent[x]=y;
            else{
                parent[y]=x;
                rank[x]++;
            }
        }
        int find(int x){
            return (parent[x]==x)?x:parent[x]=find(parent[x]);
        }
        vector<int> get(){
            return parent;
        }
    };

class Solution {
    public:
        long long int numberOfPairs(vector<vector<int>> &pairs,int p,int n)
        {
            DisjointSet d(n);
            for(int i=0;i<p;i++){
                int a=pairs[i][0];
                int b=pairs[i][1];
                int x=d.find(a);
                int y=d.find(b);
                if(x!=y)
                    d.Union(x,y);
            }
            vector<int>parent;
            parent=d.get();
            for(int i=0;i<n;i++){
                parent[i]=d.find(i);
            }
            unordered_map<int,int>mpp;
            for(int i=0;i<n;i++){
                mpp[parent[i]]++;
            }
            vector<int>v;
            long long  sum=0;
            for(auto x:mpp){
                v.push_back(x.second);
                sum+=x.second;
            }
            long long ans=0;
            for(int i=0;i<v.size()-1;i++){
                ans+=(v[i])*(sum-v[i]);
                sum-=v[i];
            }
            return ans;
        }
};
