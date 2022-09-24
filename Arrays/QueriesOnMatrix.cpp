/*
gfg link - https://practice.geeksforgeeks.org/problems/queries-on-a-matrix0443/1
*/

//T.C=2*O(N^2)
    vector<vector<int>> solveQueries(int n, vector<vector<int>>q) {
       vector<vector<int>>ans(n,vector<int>(n+1,0));
        for(int i=0;i<q.size();i++)
        {
            int a=q[i][0];
            int b=q[i][1];
            int c=q[i][2];
            int d=q[i][3];
            for(int j=a;j<=c;j++)
            {ans[j][b]+=1;
             ans[j][d+1]-=1;
            }
        }
        for(int i=0;i<ans.size();i++)
        {
            for(int j=1;j<ans[i].size();j++)
            ans[i][j]+=ans[i][j-1];
            ans[i].pop_back();
        }
        return ans;
    }
