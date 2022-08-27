/*
leetcode link - https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
*/


    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int r=matrix.size();
        int c=matrix[0].size();
        int p[r][c]; //prefix matrix;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                p[i][j]=j>0?matrix[i][j]+p[i][j-1]:matrix[i][j];
            }
        }
        for(int j=0;j<c;j++){
            for(int i=0;i<r;i++){
                p[i][j]+=i>0?p[i-1][j]:0;
            }
        }
        int maxi=INT_MIN;
      /*x1,y1 is row and col same x2,y2 (corrdinates : x1,y1      x1,y2
                                                       x2,y1      x2,y2)
      */
        for(int x1=0;x1<r;x1++){
            for(int y1=0;y1<c;y1++){
                for(int x2=x1;x2<r;x2++){
                    for(int y2=y1;y2<c;y2++){
                        int common=x1>0&&y1>0 ?p[x1-1][y1-1] : 0;
                        int top=x1>0 ? p[x1-1][y2]: 0;
                        int left= y1>0 ? p[x2][y1-1] : 0;
                        int area=p[x2][y2]-(top+left)+common;
                        if(area<=k) maxi=max(maxi,area);
                    }
                }
            }
        }
        return maxi;
    }
