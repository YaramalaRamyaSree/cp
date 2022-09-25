/*
leetcode link- https://leetcode.com/problems/find-k-closest-elements/
*/

//T.C=O(NlogK)
void golden(pair<int,int>p,vector<int>&ans)
{
    ans.push_back(p.second);
}
vector<int> findClosestElements(vector<int>& arr, int k, int x) 
{
    vector<int>ans;
    priority_queue<pair<int,int>>st;
      for(int i=0;i<arr.size();i++)
      {
          int dif=abs(x-arr[i]);
          st.push({dif,arr[i]});
          if(st.size()==k+1)
              st.pop();
      }
    while(!st.empty())
    {
        golden(st.top(),ans);
        st.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}
