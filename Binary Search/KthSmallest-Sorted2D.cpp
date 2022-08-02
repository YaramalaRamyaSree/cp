/*
LEETCODE LINK - https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
*/
  
//T.C=O(log(range)*log(n+m)) range=matrix[n-1][m-1]-matrix[0][0] S.C=O(1)

//here range is not index its larger elemnet and smaller element .
    int kthSmallest(vector<vector<int>>& matrix, int k) { 
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n-1][n-1], mid;
        //int ans;
        while(left<=right)
        {
            mid = left + (right-left)/2;
            int count = 0;
                  
            for(int i=0; i<n; i++)
            { 
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid)- matrix[i].begin();
                // upper bound gives iterator where number is > mid and count is the count of ele less than ande equal to mid in the matrix                  
            }          
            if(count < k)
                left = mid+1;
            else {
                //ans mid;
                right = mid-1;
            }
        }
        
      return left; //return right+1; or return ans;
    }

//instead of stl function upper_bound we can write our own function to count in log(m+n)

    int lessEqual(vector<vector<int>>& matrix, int target){   // for lessEqual => T.C=O(log(n+m))
        int i=0,j=matrix[0].size()-1;
        int count=0;
        while(i<matrix.size() && j>=0){
            if(matrix[i][j]>target)
                j--;
            else
            {
                count+=j+1;
                i++;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) { 
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n-1][n-1], mid;
        //int ans;
        while(left<=right)
        {
            mid = left + (right-left)/2;
            int count = lessEqual(matrix,mid);
            if(count < k)
                left = mid+1;
            else {
                //ans mid;
                right = mid-1;
            }
        }
        
      return left; //return right+1; or return ans;
    }
