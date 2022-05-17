/*
Difference between below 2 questions is 
first one - matrix sorted row wise and The first integer of each row is greater than the last integer of the previous row.
second one - just soeted row wise and also sorted column wise.
*/

/*
leetcode link - https://leetcode.com/problems/search-a-2d-matrix/
*/

    // T.C=O(log(M+N)) S.C=O(1)

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col=matrix[0].size();
        int low=0,mid,high=(matrix.size()*col)-1;
        while(low<=high){
            mid=low+(high-low)/2;
            if(matrix[mid/col][mid%col]==target)
                return true;
            else if (matrix[mid/col][mid%col]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return false;
    }

/*
gfg link - https://practice.geeksforgeeks.org/problems/search-in-a-matrix17201720/1/
*/


  // T.C=O(M+N) S.C=O(1)

	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    // your code here
	    int i =0,j =M-1;
	    while(i<N && j>=0){
	        if(mat[i][j]==X)
	         return 1;
	        else if(mat[i][j]>X)
	            j--;
	        else
	            i++;
	    }
	    return 0;
	}
