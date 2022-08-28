/*
leetcode link - https://leetcode.com/problems/sort-the-matrix-diagonally/
*/

//T.C=O(m+n)*k S.C=O(1)
    void sort(vector<vector<int>>& mat,int row,int col,int r,int c){
      //used counting sort as numbers in range 1 to 100
        int cnt[101]={0};
        int rows=row,cols=col;
        while(row<r && col<c){
            cnt[mat[row][col]]++;
            row++;col++;
        }
        row=rows;col=cols;
        for(int i=1;i<101;i++){
            if(cnt[i]>0){
                int count=cnt[i];
                while(count-->0){
                    mat[row][col]=i;
                    row++;
                    col++;
                }
            }
        }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        //for rows
        for(int i=0;i<c;i++){
            sort(mat,0,i,r,c);
        }
        //for cols
        for(int i=1;i<r;i++){
            sort(mat,i,0,r,c);
        }
        return mat;
    }
