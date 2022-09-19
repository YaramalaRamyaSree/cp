/*
gfg link - https://practice.geeksforgeeks.org/problems/smallest-number-on-left3403/1
*/

//T.C=O(N) S.C=O(N)

    vector<int> leftSmaller(int n, int a[]){
      vector<int>ans;
      stack<int>s;
      ans.push_back(-1);
      s.push(a[0]);
      for(int i=1;i<n;i++){
          while(!s.empty()&&s.top()>=a[i])
            s.pop();
          if(s.empty()){
            ans.push_back(-1);
            s.push(a[i]);}
         else
            {
                ans.push_back(s.top());
                s.push(a[i]);
            }
          
      }
      return ans;
    }
