/*
gfg link - https://practice.geeksforgeeks.org/problems/count-occurences-of-a-given-word-in-a-2-d-array/1
*/

//DFS APPROACH 
    vector<pair<int,int>>d={{1,0},{0,1},{-1,0},{0,-1}};
    int ans=0;
    
    void helper(vector<vector<char>>mat,vector<vector<bool>> &vis,string target ,int m,int n,int i,int j,int curr){
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int x=i+d[k].first;
            int y=j+d[k].second;
            if(x>=0 && x<m && y>=0 && y<n && target[curr]==mat[x][y] &&vis[x][y]==false){
                if(curr==target.size()-1)
                    ans++;
                else
                    helper(mat,vis,target,m,n,x,y,curr+1);
            }
        }
        vis[i][j]=false;
    }
    
    int findOccurrence(vector<vector<char>> &mat, string target){
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==target[0]){
                    if(target.size()==1)
                        ans++;
                    else
                     helper(mat,vis,target,m,n,i,j,1);
                }
            }
        }
        return ans;
    }
