/*
leetcode link - https://leetcode.com/problems/merge-intervals/
*/

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      
        vector<vector<int>> mi; // mergedintervals
      
        sort(intervals.begin(),intervals.end()); //sorting intervals - trick to easily merge 
      
        vector<int> temp=intervals[0]; 
      
        for(int i=1;i<intervals.size();i++) {
          
            if(intervals[i][0]<=temp[1])  //when to merge 
                temp[1]=max(temp[1],intervals[i][1]);
          
            else{
                mi.push_back(temp);
                temp=intervals[i];
            }
        }
      
        mi.push_back(temp);
      
        return mi;
      
    }
