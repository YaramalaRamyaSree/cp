/*
gfg link - https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#
*/

//T.C=O(M^N) => T(N)=M*T(N-1) ,S.C=O(N)

bool canColor(int node,vector<int>&color,bool graph[101][101],int n,int c){
    for(int i=0;i<n;i++){
        if(graph[node][i])
            if(color[i]==c)
                return false;
    }
    return true;
}
bool isPossible(int node,vector<int>&color,bool graph[101][101], int m, int n){
    if(node==n) return true;
    for(int i=1;i<=m;i++){
        if(canColor(node,color,graph,n,i)){
            color[node]=i;
            if(isPossible(node+1,color,graph,m,n)) return true;
            color[node]=0;
        }
    }
        return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int> color(n,0);
    return isPossible(0,color,graph,m,n);
}
