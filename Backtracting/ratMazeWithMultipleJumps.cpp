/*
gfg link - https://practice.geeksforgeeks.org/problems/rat-maze-with-multiple-jumps3852/1#
*/
  //T.C=O(ROWS*COLS*K),K=max(matrix[i][j])
    bool withinboundary(int i,int j,vector<vector<int>>&matrix){
       if(i>=matrix.size()||j>=matrix[0].size()||matrix[i][j]==0)
       return false;
       else
       return true;
   }
 
   bool ratMaze(vector<vector<int>>&matrix,vector<vector<int>>&ans,int i,int j){
       if(i==matrix.size()-1 && j==matrix[0].size()-1){
           ans[i][j]=1;
           return true;
       }
       if(withinboundary(i,j,matrix)){
           ans[i][j]=1;
           // we always try if possible take less no of jumps and move right over down 
           for(int noofsteps=1;noofsteps<=matrix[i][j];noofsteps++){
               //moving right
               if(ratMaze(matrix,ans,i,j+noofsteps)) return true;
               //moving down 
               if(ratMaze(matrix,ans,i+noofsteps,j)) return true;
           }
           ans[i][j]=0;
       }
       return false;
   }

	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	   vector<vector<int>>ans(matrix.size(),vector<int>(matrix[0].size(),0));
	   if(ratMaze(matrix,ans,0,0))
	   return ans;
	   else
	   return  {{-1}};
	   
	}

